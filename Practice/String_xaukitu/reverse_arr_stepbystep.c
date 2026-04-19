#include <stdio.h>
#include <string.h>

void remove_target(char* arr[],const char* target)
{
    for(int i = 0; arr[i]!=NULL; i++)
    {
        if(strcmp(arr[i], target) == 0)
        {
            int j = i;
            while(arr[j]!= NULL)
            {
                arr[j] = arr[j+1];
                j++;
            }
            i--;
        }
    }
}
int arr_len(char* ar[])
{
    int count = 0;
    while(ar[count] != NULL)
    {
        count++;
    }
    return count;
}
void reverse_arr(char* arr[])
{
    int l = 0;
    int r = arr_len(arr) - 1;
    while(l < r)
    {
        char* temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}
int main()
{
    char str[1000] = {0};
    char str2[1000] = {0};
    fgets(str, sizeof(str), stdin);
    
    memcpy(str2, str, sizeof(str));
    char *arr[10] = {0};
    int i = 0;
    char* tok = strtok(str2, " ");
    while(tok !=NULL)
    {
        arr[i++] = tok;
        tok = strtok(NULL, " ");
    }
    remove_target(arr, "thanh");
    reverse_arr(arr);
    for(int i = 0;i < 10; i++)
    {
        printf("arr : %s\n", arr[i]);
    }

    printf("%s\n", str);
    return 0;
}