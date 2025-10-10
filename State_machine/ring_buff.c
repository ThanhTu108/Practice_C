#include "ring_buff.h"
#include <stdio.h>
enum ring_stt ring_init(struct RING_BUFF_t* ring, int* buf_data, int size)
{
    if(buf_data == NULL || size == 0)
    {
        printf("eeee");
        return ring_err;
    }
    ring->buffer = buf_data;
    ring->size = size;
    ring->rd = 0;
    ring->wr = 0;
    return ring_ok;
}

enum ring_stt ring_put(struct RING_BUFF_t* ring, int data)
{
    int temp = ring->wr;
    temp++;
    if(temp >= ring->size)
    {
        temp = 0;
    }
    if(temp == ring->rd)
    {
        return ring_err;
    }
    ring->buffer[ring->wr] = data;
    ring->wr = temp;
    return ring_ok;
}

enum ring_stt ring_get(struct RING_BUFF_t* ring, int* data)
{
    if(ring->rd == ring->wr)
    {
        return ring_err;
    }
    *data = ring->buffer[ring->rd];
    ring->rd++;
    if(ring->rd >= ring->size)
    {
        ring->rd = 0;
    }
    return ring_ok;
}
