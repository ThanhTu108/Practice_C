#include <stdio.h>
typedef void (*func_t) (int, int);
void sum(int x, int y)
{
    printf("x + y = %d\n", x+y);
}

void hieu(int x, int y)
{
    printf("x + y = %d\n", x-y);
}

int main()
{
    func_t func,func1, func2;
    func = sum;
    func(1,2);
    
    return 0;
}