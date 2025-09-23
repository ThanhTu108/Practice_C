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



int main()
{
    char c = 'A';
    printf("%d", is_lower(c));
    return 0;
}