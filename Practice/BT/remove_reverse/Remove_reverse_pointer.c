#include <stdio.h>
#include <string.h>


void swap(char* a[], char* b[])
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int remove_target(char* str, char* arr[], char* target)
{
    int i = 0;
    char* token = strtok(str, " ");
    while(token != NULL)
    {
        if(strcmp(token, target) != 0)
        {
            arr[i++] = token;
        }
        token = strtok(NULL, " ");
    } 
    arr[i] = "\0";
    return i;
}
void reverse(char* arr[], int n)
{
    int l = 0;
    int r = n - 1;
    while(l < r)
    {
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }
}
int main ()
{
    char c[100];
    fgets(c, sizeof(c), stdin);
    int i = 0;
    while(c[i] != '\0')
    {
        if(c[i] == '\n')
        {
            c[i] = '\0';
        }
        i++;
    }
    char* temp[10] = {0};
    int n = remove_target(c, temp,"thanh");
    reverse(&temp[0], n);
    for(int i = 0; temp[i] != '\0'; i++)
    {
        printf("%s ", temp[i]);
    }
    return 0;
}