#include <stdio.h>
#include <string.h>
void Str_get(char* str, int size)
{   
    printf("Enter string: \n");
    fgets(str, size, stdin);
}
void remov_white_space(char* str)
{
    for(int i = 0; str[i]!='\0'; i++)
    {
        if(str[i] == ' ')
        {
            // *(str + i) = *(str+i+1);
            for(int j = i; str[j]!='\0'; j++)
            {
                *(str + j) = *(str+j+1);
            }
            i--;
        }
    }
}
void remov_space(char* str)
{
    int count = 0;
    for(int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
            str[count++] = str[i]; 
    }
    str[count] = '\0';
}
int main()
{
    char str[100];
    Str_get(str, 100);
    printf("before %d\n", strlen(str));
    remov_space(str);
    printf("before %d\n", strlen(str));
    printf("%s", str);
    return 0;
}