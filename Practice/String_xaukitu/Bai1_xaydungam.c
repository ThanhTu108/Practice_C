#include <stdio.h>

int is_lower(char c)
{
    if(c>='a' && c <='z')
    {
        return 1;
    }
    return 0;
}

int is_uper(char c)
{
    if(c>='A' && c <= 'Z')
    {
        return 1;
    }
    return 0; 
}

int is_alpha(char c)
{
    if((c>='a' && c<='z') || (c >= 'A' && c <='Z'))
    {
        return 1;
    } 
    return 0;
}

int is_digit(char c)
{
    if(c>='0' && c <='9')
    {
        return 1;
    }
    return 0;
}

char to_lower(char c)
{

    if(is_uper(c))
    {
        c+=32;
    }
    return c;
}

char to_lower_2(char c)
{
    if(c >='A' && c <='Z')
    {
        c+=32;
    }
    return c;
}


char to_uper(char c)
{
    if(is_lower(c))
    {
        c-=32;
    }
    return c;
}

char to_uper_2(char c)
{
    if(c >='a' && c <='z')
    {
        c-=32;
    }
    return c;
}

int mystrlen(char* c)
{
    int cnt = 0;
    while(*(c + cnt)!='\0')
    {
        ++cnt;
    }
    return cnt;
}

char* mystrlwr(char* c)
{
    for(int i = 0; c[i]!='\0'; i++)
    {
        if(*(c+i) >='A' && c[i] <= 'Z')
        {
            *(c+i)+=32;
            //c[i] = to_lower(c[i]);
        }
    }
    return c;

}
int min(int a, int b)
{
    return a<b?a:b;
}

int mystrcmp(char* a, char* b)
{
    int n1 = mystrlen(a);
    int n2 = mystrlen(b);
    for(int i = 0; i <min(n1, n2); i++)
    {
        if(a[i] != b[i])
        {
            if(*(a+i) > b[i])   return 1;
            else return -1;
        }
    }
    if(n1 == n2)
    {
        return 0;
    }
    else if(n1 > n2)    return 1;
    else return -1;
}



int main()
{
    char s[] = "HeLLo";
    printf("%d\n", &s[0]);
    printf("%s\n", mystrlwr(s));

    return 0;
}