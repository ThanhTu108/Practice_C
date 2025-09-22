#include <stdio.h>
void enter_number(int* a, int*b)
{
    printf("Enter number a: ");
    scanf("%d", a);
    printf("Enter number b: ");
    scanf("%d", b);
}
int* sum(int* a, int* b)
{
    static int sum;
    sum = 0;
    sum = *a + *b;
    return &sum;
}

int main()
{
    int a, b;
    int* res;
    enter_number(&a, &b);
    res = sum(&a, &b);
    printf("sum = %d", *res);
    return 0;
}