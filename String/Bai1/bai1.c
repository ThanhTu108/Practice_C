#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "Deviot.vn";
    char* find_t = strstr(str, "t");
    if(find_t)
    {
        printf("index of t: %d\n", find_t - str);
    }
    return 0;
}