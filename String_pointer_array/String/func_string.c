#include <stdio.h>

int is_lower(char c)
{
    if(c>='a' && c<='z')
    {
        return 1;
    }
    return 0;
}

int is_upper(char c)
{
    if(c>='A' && c<='Z')
    {
        return 1;
    }
    return 0;
}

int is_alpha(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
        return 1;
    }
    return 0;
}

int is_digit(char c)
{
    if(c >='0' && c<='9')
    {
        return 1;
    }
    return 0;
}

char to_lower(char c)
{
    if(c>='A' && c<='Z')
    {
        c+=32;
    }
    return c;
}
char to_upper(char c)
{
    if(c>='a' && c<='z')
    {
        c-=32;
    }
    return c;
}



int main()
{
    char c = 'A';
    printf("%d \n", is_lower(c));
    return 0;
}