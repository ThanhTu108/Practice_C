#include <stdio.h>
#include "mul_queue.h"

int main()
{
    struct Func f = 
    {
        .create = create_queue,
        .enqueue = enqueue,
        .dequeue = dequeue,
        .front = getFront,
        .rear = getRear,
    };
    struct buf_data_t data1 = 
    {
        .buf = {1,2,3,4,5},
        .len = 5,
    };
    struct buf_data_t data_out;
    struct Queue_t* queue = f.create(5);
    f.enqueue(queue, data1);
    f.dequeue(queue, &data_out);
    printf("%d", data_out.len);
    return 0;
}