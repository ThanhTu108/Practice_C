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

struct ringbuf *create_ring(int capacity);
enum ring_stt get_ring(struct ringbuf*, int* data);
enum ring_stt write_ring(struct ringbuf*, int data);

#endif
