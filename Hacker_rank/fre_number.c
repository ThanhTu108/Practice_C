#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int is_digit(char c)
{
    if(c>='0' && c<='9')
    {
        return 1;
    }
    return 0;
}
void fre_num(char* s, int* arr)
{
    for(int i = 0; s[i]!='\0'; i++)
    {
        if(is_digit(s[i]))
        {
            arr[s[i] - '0']+=1;
        }
    }
}
int main() {
    char* s;
    int arr[10] = {0, 0 ,0 ,0 ,0, 0 ,0 ,0 ,0 ,0};
    s = (char*)malloc(1024 * sizeof(s));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    fre_num(s, &arr);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
