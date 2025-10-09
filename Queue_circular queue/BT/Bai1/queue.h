#ifndef __QUEUE_H
#define __QUEUE_H

struct Queue_t
{
    int front;
    int rear;
    int size_use;
    int capacity;
    int* arr;
};
enum queue_stt_t
{
    queue_ok = 0,
    queue_err = -1,
};
typedef int(*Get_func)(struct Queue_t* );
typedef struct Queue_t*(*Create_func)(int);
typedef enum queue_stt_t (*En_func)(struct Queue_t*, int);
typedef enum queue_stt_t (*De_func)(struct Queue_t*, int*);


struct Func
{
    Create_func create;
    Get_func front;
    Get_func rear;
    En_func enqueue;
    De_func dequeue;
};
int getFront(struct Queue_t* queue);
int getRear(struct Queue_t* queue);
struct Queue_t* create_queue(int capacity);
enum queue_stt_t enqueue(struct Queue_t* queue, int data);
enum queue_stt_t dequeue(struct Queue_t* queue, int* data);

#endif