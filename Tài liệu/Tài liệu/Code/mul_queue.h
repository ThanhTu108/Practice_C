#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE    20
#define MAX_ELEMENT 10

typedef enum{
    QUEUE_FAIL = -1,
    QUEUE_OK = 0,
}   queue_stt_t;

typedef struct
{
    int len;
    int buf[MAX_SIZE];
}   buf_data_t;

typedef struct{
    int front;      // chỉ số của phần tử đầu queue
    int rear;       // chỉ số của phần tử cuối queue
    int used;       // số phần tử đang có trong queue
    int capacity;   // dung lượng max của queue
    buf_data_t *array;     // con trỏ trỏ đến mảng tượng chưng
}   queue_t;

queue_t * create_queue(int capacity);
queue_stt_t enqueue(queue_t *queue, int *data, int len);
queue_stt_t dequeue(queue_t *queue, int *data, int *len);
