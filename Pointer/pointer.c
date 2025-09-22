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

void pointer_array()
{
    char a[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
    unsigned char* pt_arr_c = a;
    for(int i = 0; i < 10; i++)
    {
        printf("pointer array with same datatype of array: 0x%x\n", *pt_arr_c);
        pt_arr_c++;
    }

    int* pt_arr_i = a;
    for(int i = 0; i < 2; i++)
    {
        printf("pointer array with diff datatype of array: 0x%x\n", *pt_arr_i);
        pt_arr_i++;
        // int 4 byte, char 1 byte -> output= 0x04030201
    }
}
int main()
{
    // pointer_address();
    pointer_array();
    return 0;
}