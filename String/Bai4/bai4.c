#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "na bi khungggg";
    char* str_space = strstr(str, " ");
    while(str_space)
    {
        str[str_space - str] = 127;
        str_space = strstr(str, " ");
    }
    printf("Chuoi bo khoang trang: %s\n", str);
    return 0;
}