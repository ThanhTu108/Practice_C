#include <stdio.h>
#include "queue.h"
#include <time.h>

#define CAPACITY 4

void print_arr(int* arr, int len)
{
    for(int i = 0; i<len; i++)
    {
        printf("%d\t", *(arr+i));
    }
    printf("\n");
}

int main()
{
    int arr[20] = {0};
    int cnt = 0;
    static int i;
    struct Func f =
    {
        .create = create_queue,
        .front = getFront,
        .rear = getRear,
        .enqueue = enqueue,
        .dequeue = dequeue,
    };
    struct Queue_t* queue = f.create(CAPACITY);
    while(1)
    {
        enqueue(queue, i);
        i++;
        usleep(100000);
        if(dequeue(queue, arr+cnt)==queue_ok)
        {
            cnt++;
        }
        else
        {
            printf("Queue errr!!\n");
        }
        if(cnt == 20)
        {
            print_arr(arr, 20);
            cnt = 0;
        }
    }
    return 0;
}