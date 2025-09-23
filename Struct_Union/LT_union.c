#include <stdio.h>

typedef union
{
    int i;
    float f;
    char s[10];
} Type_t;

int main()
{
    Type_t value;
    value.i = 100;
    value.f = 3.5;
    strcpy(value.s, "hello");

    printf("x = %d\n", value.i);
    printf("f = %f\n", value.f);
    printf("s = %s\n", value.s);
    return 0;
}