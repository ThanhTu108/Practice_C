#include <stdio.h>
#include "min_protocol.h"
#include <windows.h>
#include "ring_buff.h"
#include <time.h>
#include <pthread.h>
struct min_context min;

enum
{
    SET = 0,
    GET,
    REQ,
} min_id_t;
typedef enum min_id_t min_id;
struct Ring_buf_t* RING;
enum ring_st_t st; 

struct data_send_t
{
    bool is_send;
    uint8_t char_send;
};

struct data_send_t data_send = 
{
    .is_send = false,
    .char_send = 0,
};
struct data_send_t data_rev;
void min_application_handler(uint8_t min_id, uint8_t const *min_payload, uint8_t len_payload, uint8_t port)
{
    printf("min_id = %d \n", min_id);
    for(int i = 0; i<len_payload; i++)
    {
        printf("0x%02x ", min_payload[i]);
    }
}
uint8_t min_send[] = {0xaa, 0xaa, 0xaa, 0x00, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05, 0x4c, 0x88, 0x20, 0x24, 0x55};
void* thread_1(void* arg) 
{
    while(1)
    {
        
        // min_send_frame(&min, SET, );
        for(int i = 0; i<sizeof(min_send); i++)
        {
            data_send.char_send = min_send[i];
            // printf("%d  ", data_send.char_send);
            data_send.is_send = true;
            sleep(1);
        }
        
    }
}

void* thread_2(void* arg) 
{
    while(1)
    {
        if(data_send.is_send == true)
        {
            data_send.is_send = false;
            data_rev = data_send;
            printf("%d  ", data_rev.char_send);
            ring_put(RING, data_rev.char_send);
        }
    }
    // usleep(100000);
}
void* thread_3(void* arg) 
{
    uint8_t RX_DATA;
    while(1)
    {
        if(ring_get(RING, &RX_DATA) == ring_ok)
        {
            min_poll(&min, &RX_DATA, 1);
        }
    }
    usleep(100000);
}

struct Func f =
{
    .init = ring_init,
    .put = ring_put,
    .get = ring_get,    
};


int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    min_init_context(&min, 0);
    st = f.init(&RING, 10);
    if(st == ring_ok)
    {
        printf("ring ok\n");
    }
    pthread_create(&thread1, NULL, thread_1, NULL);
    pthread_create(&thread2, NULL, thread_2, NULL);
    pthread_create(&thread3, NULL, thread_3, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    // uint8_t payload[] = {1,2,3,4,5};
    // min_send_frame(&min, SET, payload, sizeof(payload));
    
    return 0;
}