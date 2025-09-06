#include <stdio.h>
#include <stdint.h>
#include "ringbuf.h"
#include <time.h>
#include <errno.h>

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

void printArr(uint8_t * arr, int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

RINGBUF ring;
uint8_t ring_buf[20];

uint8_t data_read[50];
uint32_t data_cnt = 0;

int main()
{
    RINGBUF_Init(&ring, ring_buf, 20);
    static int dummy_data = 0;
    while(1)
    {
        RINGBUF_Put(&ring, dummy_data++);
        if(RINGBUF_Get(&ring, &data_read[data_cnt]) == RING_OK)
        {
            data_cnt++;
            if(data_cnt == 20){
                printArr(data_read, data_cnt);
                data_cnt = 0;
            }
        }
        msleep(100);
    }
}
