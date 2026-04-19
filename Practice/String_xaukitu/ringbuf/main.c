#include "ring.h"
#include <stdio.h>
#include <string.h>
int main()
{
    struct ringbuf* ring;
    int arr[10] = {0};
    struct ring_func f = 
    {
        .cre = create_ring,
        .get = get_ring,
        .write = write_ring,
    };
    ring = f.cre(4);

    for(int i = 0; i < 10; i++)
    {
        f.write(ring, i);
        f.get(ring, &arr[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    
    return 0;
}