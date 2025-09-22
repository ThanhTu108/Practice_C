#include <stdio.h>

void pointer_address()
{
    int x = 1000; //0x03E8
    int* pt = &x;
    printf("&x: %d\n", &x);
    printf("pt: %d\n", pt);
    printf("&pt: %d\n", &pt);
    printf("*pt: %d\n", *pt);
}
int main()
{
    pointer_address();
    return 0;
}