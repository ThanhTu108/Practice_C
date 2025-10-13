#include "ring_buff.h"
#include <stdio.h>
#include <stdlib.h>
enum ring_st_t ring_init(struct Ring_buf_t** ring, int capacity)
{
    *ring = (struct Ring_buf_t*)malloc(sizeof(struct Ring_buf_t));
    if(*ring == NULL)
    {
        printf("cannot allocate memory for ringbuff");
        return ring_err;
    }
    (*ring)->rd = 0;
    (*ring)->wr = 0;
    (*ring)->size_use = 0;
    (*ring)->capacity = capacity;
    (*ring)->buff_data = malloc(capacity*(sizeof(int)));
    return ring_ok;
}

enum ring_st_t ring_put(struct Ring_buf_t* ring, int data)
{
    if(ring->size_use == ring->capacity)
    {
        printf("ring full");
        return ring_err;
    }
    ring->buff_data[ring->wr] = data;
    ring->wr = (ring->wr + 1) % (ring->capacity);
    ring->size_use++;
    return ring_ok;
}

enum ring_st_t ring_get(struct Ring_buf_t* ring, int* data)
{
    if(ring->size_use == 0 )
    {
        // printf("ring empty\n");
        return ring_err;
    }
    *data = ring->buff_data[ring->rd];
    ring->rd = (ring->rd + 1) % (ring->capacity);
    ring->size_use--;
    return ring_ok;
}