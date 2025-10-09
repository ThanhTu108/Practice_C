#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
struct Queue_t* create_queue(int capacity)
{
    struct Queue_t* newqueue =(struct Queue_t*)malloc(sizeof(struct Queue_t));
    newqueue->front = 0;
    newqueue->rear = -1;
    newqueue->size_use = 0;
    newqueue->capacity = capacity;
    newqueue->arr = (int*)malloc(capacity * sizeof(int));
    return newqueue;
}

int getFront(struct Queue_t* queue)
{
    return queue->arr[queue->front];
}

int getRear(struct Queue_t* queue)
{
    return queue->arr[queue->rear];
}
static bool isFull(struct Queue_t* queue)
{
    return (queue->size_use == queue->capacity);
}
static bool isEmpty(struct Queue_t* queue)
{
    return (queue->size_use == 0);
}
enum queue_stt_t enqueue(struct Queue_t* queue, int data)
{
    if(isFull(queue))
    {
        return queue_err;
    }
    queue->rear = (queue->rear+1) % (queue->capacity);
    queue->size_use++;
    queue->arr[queue->rear] = data;
    return queue_ok;
}

enum queue_stt_t dequeue(struct Queue_t* queue, int* data)
{
    if(isEmpty(queue))
    {
        return queue_err;
    }
    *data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % (queue->capacity);
    queue->size_use--;
    return queue_ok;
}