#include <stdio.h>
#include "ring_buf.h"
#include <time.h>

struct RING_BUFF_t ring;
uint8_t ring_buff[20];
void print_arr(uint8_t* arr, int len)
{
    printf("..........\n");
    for(int i = 0; i<len; i++)
    {
        printf("%3d ", *(arr+i));
    }
    printf("\n");
}
int main()
{
    uint8_t data_read[30];
    uint32_t count = 0;
    
    Ring_init(&ring, ring_buff, 20);
    static int dummy_data = 0 ;
    while(1)
    {
        Ring_put(&ring, dummy_data++);
        if(Ring_get(&ring, &data_read[count]) == ring_buf_ok)
        {
            count++;
            if(count == 20)
            {
                print_arr(data_read, 20);
                count = 0;
            }
        }
        usleep(100000);
    }
    
    return 0;
}