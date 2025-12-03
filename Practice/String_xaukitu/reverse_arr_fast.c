#include <stdio.h>
#include <string.h>

int reverse_arr_target(char* arr[], char* str, char* target)
{
    int count = 0;
    char* tok = strtok(str, " ");
    while(tok != NULL)
    {
        if(strcmp(tok, target) != 0)
        {
            arr[count] = tok;
            count++;
        }
        tok = strtok(NULL, " ");
    }
    int l = 0;
    int r = count - 1;
    while(l < r)
    {
        char* temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    } 
    return count;
}
void print_arr(char* arr[], int count)
{
    printf("Arr affter reverse\n");
    for(int i = 0; i < count; i++)
    {
        printf("Arr[%d]: %s\n", i, arr[i]);
    }
}
int main()
{
    char* arr[100] = {0};
    char str[1000] = {0};
    fgets(str, sizeof(str), stdin);
    int len = reverse_arr_target(arr, str, "thanh");
    print_arr(arr, len);
    return 0;
}