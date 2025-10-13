#include "min_protocol.h"

#define min_debug_print     printf

static void crc32_init_context(struct crc32_context *context)
{
    context->crc = 0xffffffffU;
}

static void crc32_step(struct crc32_context *context, uint8_t byte)
{
    uint32_t j;
    context->crc ^= byte;
    for (j = 0; j < 8; j++) {
        uint32_t mask = (uint32_t) - (context->crc & 1U);
        context->crc = (context->crc >> 1) ^ (0xedb88320U & mask);
    }
}

static uint32_t crc32_finalize(struct crc32_context *context)
{
    return ~context->crc;
}

static void stuffed_tx_byte(struct min_context* self, uint8_t byte, bool crc)
{
    //transmit data
    min_tx_byte(self->port, byte);
    if(crc)
    {
        crc32_step(&self->tx_checksum, byte);
    }
    
    if(byte == HEADER_BYTE)
    {
        if(--self->tx_header_byte_countdown == 0)
        {
            min_tx_byte(self->port, STUFF_BYTE);
            self->tx_header_byte_countdown = 2U;
        }
    }
    else 
    {
        self->tx_header_byte_countdown = 2U;
    }
}

static void on_wire_bytes(struct min_context *self, uint8_t id_control, uint8_t seq, uint8_t const *payload_base, uint16_t payload_offset, uint16_t payload_mask, uint8_t payload_len)
{
    uint8_t n, i;
    uint32_t checksum;
    self->tx_header_byte_countdown = 2U;
    crc32_init_context(&self->tx_checksum);
    min_tx_start(self->port);

    min_tx_byte(self->port, HEADER_BYTE);
    min_tx_byte(self->port, HEADER_BYTE);
    min_tx_byte(self->port, HEADER_BYTE);

    stuffed_tx_byte(self, id_control, true);
    stuffed_tx_byte(self, payload_len, true);

    for(i = 0, n = payload_len; n>0; n--, i++)
    {
        stuffed_tx_byte(self, *(payload_base+payload_offset), true);
        ++payload_offset;
        payload_offset&= payload_mask;
    }

    checksum = crc32_finalize(&self->tx_checksum);

    stuffed_tx_byte(self, (uint8_t)((checksum >> 24) & 0xffU), false);
    stuffed_tx_byte(self, (uint8_t)((checksum >> 16) & 0xffU), false);
    stuffed_tx_byte(self, (uint8_t)((checksum >> 8) & 0xffU), false);
    stuffed_tx_byte(self, (uint8_t)((checksum >> 0) & 0xffU), false);
    min_tx_byte(self->port, EOF_BYTE);
    min_tx_finished(self->port);
}

static void valid_frame_received(struct min_context* self)
{
    uint8_t id_control = self->rx_frame_id_control;
    uint8_t* payload = self->rx_frame_payload_buf;
    uint8_t payload_len = self->rx_control;
    min_application_handler(id_control & (uint8_t)0x3fU, payload, payload_len, self->port);
}

static void rx_byte(struct min_context* self, uint8_t byte)
{
    uint32_t crc;
    if(self->rx_header_bytes_seen == 2)
    {
        self->rx_header_bytes_seen = 0;
        if(byte == HEADER_BYTE)
        {
            self->rx_frame_state = RECEIVING_ID_CONTROL;
            return;
        }
        if(byte == STUFF_BYTE)
        {
            return;
        }
        else
        {
            self->rx_frame_state = SEARCHING_FOR_SOF;
            return;
        }
    }

    if(byte == HEADER_BYTE)
    {
        self->rx_header_bytes_seen++;
    }
    else
    {
        self->rx_header_bytes_seen = 0;
    }

    switch(self->rx_frame_state)
    {
        case SEARCHING_FOR_SOF:
            break;
        case RECEIVING_ID_CONTROL:
            self->rx_frame_id_control = byte;
            self->rx_frame_payload_bytes = 0;
            crc32_init_context(&self->rx_checksum);
            crc32_step(&self->rx_checksum, byte);
            self->rx_frame_seq = 0;
            self->rx_frame_state = RECEIVING_LENGTH;
            break;
        case RECEIVING_SEQ:
            self->rx_frame_seq = byte;
            crc32_step(&self->rx_checksum, byte);
            self->rx_frame_state = RECEIVING_LENGTH;
            break;
        case RECEIVING_LENGTH:
            self->rx_frame_length = byte;
            self->rx_control = byte;
            crc32_step(&self->rx_checksum, byte);
            if(self->rx_frame_length > 0)
            {
                if(self->rx_frame_length <=MAX_PAYLOAD)
                {
                    self->rx_frame_state = RECEIVING_PAYLOAD;
                }
                else
                {
                    min_debug_print("Dropping frame because length %d > MAX_PAYLOAD %d\n", self->rx_frame_length, MAX_PAYLOAD);
                    self->rx_frame_state = SEARCHING_FOR_SOF;
                }
            }
            else
            {
                self->rx_frame_state = RECEIVING_CHECKSUM_3;
            }
            break;
        case RECEIVING_PAYLOAD:
            self->rx_frame_payload_buf[self->rx_frame_payload_bytes++] = byte;
            crc32_step(&self->rx_checksum, byte);
            if(--self->rx_frame_length == 0)
            {
                self->rx_frame_state = RECEIVING_CHECKSUM_3;
            }
            break;
        case RECEIVING_CHECKSUM_3:
            self->rx_frame_checksum = ((uint32_t)byte) << 24;
            self->rx_frame_state = RECEIVING_CHECKSUM_2;
            break;
        case RECEIVING_CHECKSUM_2:
            self->rx_frame_checksum |= ((uint32_t)byte) << 16;
            self->rx_frame_state = RECEIVING_CHECKSUM_1;
            break;
        case RECEIVING_CHECKSUM_1:
            self->rx_frame_checksum |= ((uint32_t)byte) << 8;
            self->rx_frame_state = RECEIVING_CHECKSUM_0;
            break;
        case RECEIVING_CHECKSUM_0:
            self->rx_frame_checksum |=byte;
            crc = crc32_finalize(&self->rx_checksum);
            if(self->rx_frame_checksum != crc)
            {
                min_debug_print("Checksum failed, received 0x%08X, computed 0x%08X\n", self->rx_frame_checksum, crc);
                // Frame fails the checksum and so is dropped
                self->rx_frame_state = SEARCHING_FOR_SOF;
            }
            else
            {
                self->rx_frame_state = RECEIVING_EOF;
            }
            break;
        case RECEIVING_EOF:
            if(byte == 0x55u)
            {
                valid_frame_received(self);
            }
            else
            {
                min_debug_print("Received invalid EOF 0x%02X\n", byte);
            }
            self->rx_frame_state = SEARCHING_FOR_SOF;
            break;
        default:
            min_debug_print("Received byte 0x%02X in invalid state %d\n", byte, self->rx_frame_state);
            self->rx_frame_state = SEARCHING_FOR_SOF;
            break;
    }
}

void min_poll(struct min_context *self, uint8_t const *buf, uint32_t buf_len)
{
    uint32_t i;
    for(i = 0; i < buf_len; i++)
    {
        rx_byte(self, buf[i]);
    }
}

void min_init_context(struct min_context* self, uint8_t port)
{
    self->rx_frame_state = SEARCHING_FOR_SOF;
    self->rx_header_bytes_seen = 0;
    self->port = port;
    min_debug_print("min init complete\n");
}

void min_send_frame(struct min_context* self, uint8_t min_id, uint8_t const* payload, uint8_t payload_len)
{
    on_wire_bytes(self, min_id & (uint8_t) 0x3fU, 0, payload, 0, 0xffffU, payload_len);
}

void min_tx_start(uint8_t port)
{
    printf("\nStart send -> \n");
}

void min_tx_finished(uint8_t port)
{
    printf("\nStop send ->\n");
}
void min_tx_byte(uint8_t port, uint8_t byte)
{
    printf("0x%02x ", byte);
}
