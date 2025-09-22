#include <stdio.h>
int* Find_Max(int* x, int* y)
{
    if(*x > *y)
    {
        return x;
    }
    return y;
}
int* Find_Max_2(int x, int y)
{
    static int max;
    if(x > y)
    {
        max = x;
    }
    else if(x < y)
    {
        max = y;
    }
    return &max;
}

int main()
{
    int a = 30;
    int b = 20;
    int* res;
    int* res_2;
    res = Find_Max(&a, &b);
    printf("Max_1: %d \n", *res);

    res_2 = Find_Max_2(a, b);
    printf("Max_2: %d \n", *res_2);

    return 0;
}