#ifndef __RING_BUF_H
#define __RING_BUF_H

struct ringbuf 
{
    int rd;
    int wr;
    int* arr;
    int size_use;
    int capacity;
};

enum ring_stt 
{
    ring_ok = 0,
    ring_err = -1,
};
typedef struct ringbuf* (*create_fn)(int);
typedef enum ring_stt (*get_fn)(struct ringbuf*, int*);
typedef enum ring_stt (*write_fn)(struct ringbuf*, int);
struct ring_func 
{
    create_fn cre;
    get_fn get;
    write_fn write;
};

struct ringbuf *create_ring(int capacity);
enum ring_stt get_ring(struct ringbuf*, int* data);
enum ring_stt write_ring(struct ringbuf*, int data);

#endif