#include <stdio.h>

void Arr_get(int* pt, int* number)
{
    printf("Enter number: ");
    scanf("%d", number);
    for(int  i = 0; i < *number; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", pt+i);
    }
}

void Arr_print(int* pt, int number)
{
    for(int  i = 0; i < number; i++)
    {
        printf("arr[%d]: %d\n", i, *(pt + i));
    }
}
int main()
{
    int arr[100];
    int number;
    Arr_get(arr, &number);
    Arr_print(arr, number);
    return 0;
}