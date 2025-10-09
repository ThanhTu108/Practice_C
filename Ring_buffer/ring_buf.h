#ifndef __RING_BUFF_H_
#define __RING_BUFF_H_

#include <stdint.h>
#include <stdbool.h>
struct RING_BUFF_t
{
    uint32_t wr;
    uint32_t rd;
    uint32_t size;
    uint8_t* buffer;
};
enum RING_STT
{
    ring_buf_ok = 0,
    ring_buf_err = -1,
};

enum RING_STT Ring_init(struct RING_BUFF_t* ring, uint8_t* buf, uint32_t maxsize);
enum RING_STT Ring_put(struct RING_BUFF_t* ring, uint8_t data);
enum RING_STT Ring_get(struct RING_BUFF_t* ring, uint8_t* data);

#endif
