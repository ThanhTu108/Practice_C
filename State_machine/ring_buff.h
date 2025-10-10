#ifndef __RING_BUFF_H_
#define __RING_BUFF_H_

struct RING_BUFF_t
{
    int rd;
    int wr;
    int size;
    int* buffer;
};

enum ring_stt
{
    ring_ok = 0,
    ring_err = -1,
};

typedef enum ring_stt (*init_func)(struct RING_BUFF_t*, int*, int);
typedef enum ring_stt (*put_func)(struct RING_BUFF_t*, int);
typedef enum ring_stt (*get_func)(struct RING_BUFF_t*, int*);

struct operation
{
    init_func init;
    put_func put;
    get_func get;
};

enum ring_stt ring_init(struct RING_BUFF_t* ring, int* buf_data, int size);
enum ring_stt ring_put(struct RING_BUFF_t* ring, int data);
enum ring_stt ring_get(struct RING_BUFF_t* ring, int* data);

#endif