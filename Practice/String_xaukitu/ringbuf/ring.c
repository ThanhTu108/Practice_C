#include <stdio.h>
#include "ring.h"
#include <stdbool.h>
#include <stdlib.h>
struct ringbuf *create_ring(int capacity)
{
    struct ringbuf* ring = (struct ringbuf*)malloc(sizeof(struct ringbuf));
    ring->capacity = capacity;
    ring->rd = 0;
    ring->wr = 0;
    ring->arr = (int*)malloc(capacity* sizeof(int));
    return ring;
}
enum ring_stt get_ring(struct ringbuf* ring, int* data)
{
    if(ring->rd == ring->wr)
    {
        return ring_err;
    }
    *data = ring->arr[ring->rd];
    ring->rd = (ring->rd + 1) % (ring->capacity); 
    return ring_ok;
}
enum ring_stt write_ring(struct ringbuf* ring, int data)
{
    if((ring->wr + 1)%(ring->capacity) == ring->rd)
    {
        return ring_err;
    }
    ring->arr[ring->wr] = data;
    ring->wr = (ring->wr + 1)%(ring->capacity);
    return ring_ok;
}