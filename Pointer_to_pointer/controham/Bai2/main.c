#include <stdio.h>
#include "lib.h"

void printf_A()
{
    printf("aaaaa");
}
void printf_B()
{
    printf("bbbbbb");
}
void printf_C()
{
    printf("ccccccc");
}

int main()
{
    activate_function(1, printf_A);
    activate_function(2, printf_B);
    activate_function(3, printf_C);
    return 0;
}