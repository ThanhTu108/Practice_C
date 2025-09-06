#include <stdint.h>
#include <stdbool.h>

typedef enum{
    QUEUE_FAIL = -1,
    QUEUE_OK = 0,
}   queue_stt_t;

typedef struct{
    int front;      // chỉ số của phần tử đầu queue
    int rear;       // chỉ số của phần tử cuối queue
    int used;       // số phần tử đang có trong queue
    int capacity;   // dung lượng max của queue
    int *array;     // con trỏ trỏ đến mảng tượng chưng
}   queue_t;

queue_t * create_queue(int capacity);
queue_stt_t enqueue(queue_t *queue, int item);
queue_stt_t dequeue(queue_t *queue, int *item);
int getFront(queue_t *queue);
int getRear(queue_t *queue);
