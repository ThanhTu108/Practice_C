#include <stdio.h>
#include "queue.h"


int main()
{
    struct Queue_t* queue = create_queue(5);
    int data;
    en_queue(queue, 1);
    en_queue(queue, 2);
    en_queue(queue, 3);
    en_queue(queue, 4);
    en_queue(queue, 5);
    
    printf("Front: %d\n", getFront(queue));
    printf("Rear: %d\n", getRear(queue));
    printf("\n");
    de_queue(queue, &data);
    en_queue(queue, 6);
    printf("Front: %d\n", getFront(queue));
    printf("Rear: %d\n", getRear(queue));
    return 0;
}