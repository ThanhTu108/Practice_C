#include "ring.h"
#include <stdio.h>
#include <string.h>
int main()
{
    struct ringbuf* ring;
    int arr[10] = {0};
    ring = create_ring(4);
    for(int i = 0; i < 10; i++)
    {
        write_ring(ring, i);
        get_ring(ring, &arr[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    
    return 0;
}