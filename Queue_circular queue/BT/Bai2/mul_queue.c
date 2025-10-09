#include <stdlib.h>
#include "mul_queue.h"
#include <stdbool.h>
#include <stdio.h>
struct Queue_t* create_queue(int capacity)
{
    struct Queue_t* newqueue =(struct Queue_t*)malloc(sizeof(struct Queue_t));
    if(newqueue == NULL)
    {
        printf("Cannot allocate newqueue\n");
        return NULL;
    }
    newqueue->front = 0;
    newqueue->rear = -1;
    newqueue->size_use = 0;
    newqueue->capacity = capacity;
    newqueue->buffer = (struct buf_data_t*)malloc(capacity*sizeof(struct buf_data_t));
    if(newqueue->buffer == NULL)
    {
        printf("Cannot allocate buffer\n");
        return NULL;
    }
    return newqueue;
}

struct buf_data_t getFront(struct Queue_t* queue)
{
    return queue->buffer[queue->front];
}
struct buf_data_t getRear(struct Queue_t* queue)
{
    return queue->buffer[queue->rear];
}

static bool isFull(struct Queue_t* queue)
{
    return (queue->size_use == queue->capacity);
}
static bool isEmpty(struct Queue_t* queue)
{
    return (queue->size_use == 0);
}
enum Queue_stt enqueue(struct Queue_t* queue, struct buf_data_t data)
{
    if(isFull(queue))
    {
        printf("aaaaa");
        return queue_err;
    }
    queue->rear = (queue->rear+1)%(queue->capacity);
    queue->buffer[queue->rear] = data;
    queue->size_use++;
    return queue_ok;
}
enum Queue_stt dequeue(struct Queue_t* queue, struct buf_data_t* data)
{
    if(isEmpty(queue))
    {
        return queue_err;
    }
    *data = queue->buffer[queue->front];
    queue->front = (queue->front+1)%(queue->capacity);
    queue->size_use--;
    return queue_ok;
}


