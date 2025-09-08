#include <string.h>
#include <stdio.h>

#define MAX_LEN 256

int main()
{
    char* str;
    str = (char*)malloc(MAX_LEN * sizeof(char));
    if(!str)
    {
        printf("Can't not allocate memory\n");
        return -1;
    }

    printf("Enter string: ");
    fgets(str, MAX_LEN, stdin);
    printf("chuoi da nhap: %s", str);
    for(int i = 0; str[i]!='\0'; i++)
    {
        if(str[i] >='a' && str[i]<='z')
        {
            str[i]-=32;
        }
        else if(str[i] >='A' && str[i]<='Z')
        {
            str[i]+=32;
        }
    }
    printf("chuoi da chuyen: %s", str);
    return 0;
}