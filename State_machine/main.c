#include <stdio.h>
#include "ring_buff.h"
#include <time.h>

struct operation ops = 
{
    .init = ring_init,
    .get = ring_get,
    .put = ring_put,
};
void print_arr(int* arr, int len)
{
    for(int i = 0;i<len; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}
struct RING_BUFF_t RING;
int buff_data[20];
int data_out[20];
int cnt = 0;
int main()
{
    int i = 0;
    ops.init(&RING, buff_data, 20);
    while(1)
    {
        ring_put(&RING, i);
        ++i;
        if(ring_get(&RING, &data_out[cnt]) == ring_ok)
        {
            cnt++;
            if(cnt == 20)
            {
                print_arr(data_out, 20);
                cnt = 0;
            }
        }
        usleep(100000);
    }

    return 0;
}