#ifndef __MUL_QUEUE_H_
#define __MUL_QUEUE_H_

#define BUFF_SIZE 20

struct buf_data_t
{
    int len;
    int buf[BUFF_SIZE];
};

struct Queue_t
{
    int front;
    int rear;
    int size_use;
    int capacity;
    struct buf_data_t* buffer;
};

enum Queue_stt
{
    queue_ok = 0,
    queue_err = -1,
};

typedef struct buf_data_t(*Get_func)(struct Queue_t* );
typedef struct Queue_t*(*Create_func)(int);
typedef enum Queue_stt (*En_func)(struct Queue_t*, struct buf_data_t);
typedef enum Queue_stt (*De_func)(struct Queue_t*, struct buf_data_t*);

struct Func
{
    Create_func create;
    Get_func front;
    Get_func rear;
    En_func enqueue;
    De_func dequeue;
};
struct buf_data_t getFront(struct Queue_t* queue);
struct buf_data_t getRear(struct Queue_t* queue);
struct Queue_t* create_queue(int capacity);
enum Queue_stt enqueue(struct Queue_t* queue, struct buf_data_t data);
enum Queue_stt dequeue(struct Queue_t* queue, struct buf_data_t* data);


#endif