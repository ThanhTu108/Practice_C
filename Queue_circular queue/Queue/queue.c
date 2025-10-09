#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
struct Queue_t* create_queue(int capacity)
{
    struct Queue_t* new_queue = (struct Queue_t*)malloc(sizeof(struct Queue_t));
    new_queue->front = 0; 
    new_queue->rear = -1;
    new_queue->capacity = capacity;
    new_queue->size_used = 0;
    new_queue->arr = (int*)malloc(capacity*sizeof(int));
    return new_queue; 
} 
static bool isEmpty(struct Queue_t* queue)
{
    return (queue->size_used == 0);
}

static bool isFull(struct Queue_t* queue)
{
    // return (queue->rear+1 == queue->capacity);
    return (queue->size_used == queue->capacity);
}
int en_queue(struct Queue_t* queue, int data)
{   
    if(isFull(queue))
    {
        // printf("Queue is full");
        return -1;
    }
    // queue->rear++;
    queue->rear = (queue->rear + 1) % (queue->capacity);
    queue->arr[queue->rear] = data;
    // *(queue->arr + queue->rear) = data;
    queue->size_used++;
    return 0;
}

int de_queue(struct Queue_t* queue, int* data)
{
    if(isEmpty(queue))
    {
        // printf("Queue is empty");
        return - 1;
    }
    *data = queue->arr[queue->front];
    // queue->front++;
    queue->front = (queue->front + 1) % (queue->capacity);
    queue->size_used--;
    return 0;
}
int getFront(struct Queue_t* queue)
{
    return queue->arr[queue->front];
}

int getRear(struct Queue_t* queue)
{
    return queue->arr[queue->rear];
}