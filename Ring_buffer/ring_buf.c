#include "ring_buf.h"
#include <stdio.h>

enum RING_STT Ring_init(struct RING_BUFF_t* ring, uint8_t* buf, uint32_t maxsize)
{
    if(buf == NULL || maxsize == 0)
    {
        printf("Buffer is null :)))\n");
        return ring_buf_err;
    }
    ring->wr = 0;
    ring->rd = 0;
    ring->buffer = buf;
    ring->size = maxsize;
    return ring_buf_ok;
}
enum RING_STT Ring_put(struct RING_BUFF_t* ring, uint8_t data)
{
    uint32_t _temp = ring->wr;
    _temp++;
    if(_temp >= ring->size)
    {
        _temp = 0;
    }
    if(_temp == ring->rd)
    {
        return ring_buf_err;
    }
    ring->buffer[ring->wr] = data;
    ring->wr = _temp;
    return ring_buf_ok;
}

enum RING_STT Ring_get(struct RING_BUFF_t* ring, uint8_t* data)
{
    if(ring->rd == ring->wr)
    {
        return ring_buf_err;
    }
    *data = ring->buffer[ring->rd];
    ring->rd++;
    if(ring->rd >= ring->size)
    {
        ring->rd = 0;
    }
    return ring_buf_ok;
}
