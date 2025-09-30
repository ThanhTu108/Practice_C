#include <stdio.h>
#include <string.h>
void swap(char* a, char* b)
{
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void sort(char a[][50], int n)
{
    for(int i = 0; i< n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(strcmp(a[j], a[j+1]) > 0)
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}
int main()
{
    char c[1000];
    gets(c);
    char word[20][50];
    int n = 0;
    char* token = strtok(c, " ");
    while(token != NULL)
    {
        strcpy(word[n], token);
        ++n;
        token = strtok(NULL, " ");
    }
    sort(word, n);
    for(int i =0 ;i < n; i++)
    {
        printf("%s ", word[i]);
    }
    return 0;
}