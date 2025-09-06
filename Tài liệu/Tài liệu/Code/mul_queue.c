#include "mul_queue.h"

queue_t * create_queue(int capacity)
{
    queue_t *qt = (queue_t *)malloc(sizeof(queue_t));
    qt->front = 0;
    qt->rear = -1;
    qt->used = 0;
    qt->capacity = capacity;
    qt->array = (buf_data_t*) malloc(capacity * sizeof(buf_data_t));
    return qt;
}

static bool isEmpty(queue_t *queue)
{
    return (queue->used == 0);
}

static bool isFull(queue_t *queue)
{
    return (queue->used == queue->capacity);
}

queue_stt_t enqueue(queue_t *queue, int *data, int len)
{
    if(isFull(queue))
        return QUEUE_FAIL;
    queue->rear = (queue->rear + 1)%queue->capacity;
    memcpy(queue->array[queue->rear].buf, data, len * sizeof(int));
    queue->array[queue->rear].len = len;
    queue->used++;
    return QUEUE_OK;
}

queue_stt_t dequeue(queue_t *queue, int *data, int *len)
{
    if(isEmpty(queue))
        return QUEUE_FAIL;
    memcpy(data, queue->array[queue->front].buf, queue->array[queue->front].len * sizeof(int));
    *len = queue->array[queue->front].len;
    queue->front = (queue->front + 1)%queue->capacity;
    queue->used--;
    return QUEUE_OK;
}


