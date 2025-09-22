#include <stdio.h>

void pointer_address()
{
    int x = 1000; //0x03E8  -> save in memory: E8 03
    int* pt = &x;
    printf("&x: %d\n", &x);
    printf("pt: %d\n", pt);
    printf("&pt: %d\n", &pt);
    printf("*pt: %d\n", *pt);

    unsigned char* ptt = &x;
    printf("&x: %d\n", &x);
    printf("ptt: %d\n", ptt);
    printf("&ptt: %d\n", &ptt);
    printf("*ptt: %d\n", *ptt);  //232 = 0xE8
    printf("*ptt: %d\n", *(ptt+1));  //0x03 = 0x03
}

void 
int main()
{
    pointer_address();
    return 0;
}