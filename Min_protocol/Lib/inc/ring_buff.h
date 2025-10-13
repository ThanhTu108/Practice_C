#ifndef __RING_H
#define __RING_H



struct Ring_buf_t
{
    int wr;
    int rd;
    int size_use;
    int capacity;
    int* buff_data;
};

enum ring_st_t
{
    ring_err = -1,
    ring_ok = 0,
};

typedef enum ring_st_t (*init_func)(struct Ring_buf_t**, int);
typedef enum ring_st_t (*put_func)(struct Ring_buf_t*, int);
typedef enum ring_st_t (*get_func)(struct Ring_buf_t*, int*);
struct Func
{
    init_func init;
    put_func put;
    get_func get;
};

enum ring_st_t ring_init(struct Ring_buf_t** ring, int capacity);
enum ring_st_t ring_put(struct Ring_buf_t* ring, int data);
enum ring_st_t ring_get(struct Ring_buf_t* ring, int* data);
#endif