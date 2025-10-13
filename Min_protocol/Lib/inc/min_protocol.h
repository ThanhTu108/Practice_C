#ifndef MIN_H
#define MIN_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifndef MAX_PAYLOAD
#define MAX_PAYLOAD (255U)
#endif

#if (MAX_PAYLOAD > 255)
#error "MIN frame payloads can be no bigger than 255 bytes"
#endif

struct crc32_context
{
    uint32_t crc;
};

struct min_context
{
    uint8_t rx_frame_payload_buf[MAX_PAYLOAD];
    uint32_t rx_frame_checksum;     //crc receive
    struct crc32_context rx_checksum;       //calc check sum for receiving data
    struct crc32_context tx_checksum;       //calc check sum for send data
    uint8_t rx_header_bytes_seen;           //countdown of header bytes to reset state
    uint8_t rx_frame_state;
    uint8_t rx_frame_payload_bytes;
    uint8_t rx_frame_id_control;               // ID and control bit of frame being received
    uint8_t rx_frame_seq;                      // Sequence number of frame being received
    uint8_t rx_frame_length;                   // Length of frame
    uint8_t rx_control;                        // Control byte
    uint8_t tx_header_byte_countdown;          // Count out the header bytes
    uint8_t port;                              // Number of the port associated with the context    //default 0/ uarrt?
};

enum
{
    HEADER_BYTE = 0xaaU,
    STUFF_BYTE = 0x55U,
    EOF_BYTE = 0x55U,
};

enum {
    SEARCHING_FOR_SOF,
    RECEIVING_ID_CONTROL,
    RECEIVING_SEQ,
    RECEIVING_LENGTH,
    RECEIVING_PAYLOAD,
    RECEIVING_CHECKSUM_3,
    RECEIVING_CHECKSUM_2,
    RECEIVING_CHECKSUM_1,
    RECEIVING_CHECKSUM_0,
    RECEIVING_EOF,
};

void min_send_frame(struct min_context* self, uint8_t min_id, uint8_t const *payload, uint8_t payload_len);
void min_poll(struct min_context *self, uint8_t const *buf, uint32_t buf_len);

// CALLBACK. Handle incoming MIN frame

void min_application_handler(uint8_t min_id, uint8_t const *min_payload, uint8_t len_payload, uint8_t port);

// CALLBACK. Send a byte on the given line.
void min_tx_byte(uint8_t port, uint8_t byte);

// CALLBACK. Indcates when frame transmission is finished; useful for buffering bytes into a single serial call.
void min_tx_start(uint8_t port);
void min_tx_finished(uint8_t port);

void min_init_context(struct min_context* self, uint8_t port);

#endif