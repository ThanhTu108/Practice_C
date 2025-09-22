#include<stdio.h>

void String_Get(char* pt, int size)
{
    printf("Enter string: ");
    fgets(pt, size, stdin);
}

int strlen(char* pt)
{
    int count;
    count = 0;
    while(pt[count] !='\0')
    {
        count++;
    }
    return count;
}
int main()
{
    char a[100];
    String_Get(a, 100);
    printf("string: %s", a);
    printf("len: %d", strlen(a));

    return 0;
}