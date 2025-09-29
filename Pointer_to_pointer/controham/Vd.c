#include <stdio.h>

typedef void (*func_t)(int, int);

void Sum(int x, int y)
{
    printf("x + y = %d\n", x+y);
}
void Subtraction(int x, int y)
{
    printf("x - y = %d\n", x-y);
}

void menu(func_t func, int x, int y)
{
    func(x, y);
}
int main()
{
    func_t func;
    int x = 4;
    int y = 3;
    int a;
    while (1)
    {
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            menu(Sum, x, y);
            break;
        
        case 2:
            menu(Subtraction, x, y);
            break;
        }
    }
    
    return 0;
}