#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdint.h>
#include <stdio.h>

struct Queue_t
{
    int front;
    int rear;
    int size_used;
    int capacity;
    int* arr;
};

struct Queue_t* create_queue(int capacity);
int en_queue(struct Queue_t* queue, int data);
int de_queue(struct Queue_t* queue, int* data);
int getFront(struct Queue_t* queue);
int getRear(struct Queue_t* queue);

#endif