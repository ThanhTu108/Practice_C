#include <stdio.h>
void Arr_get(int* pt, int* num)
{
    printf("Enter number: ");
    scanf("%d", num);
    for(int i = 0; i<*num; i++)
    {
        printf("Arr[%d]: ", i+1);
        scanf("%d", (pt+i));
    }
}

void Arr_Print(int* pt, int num)
{
    printf("...............\n");
    for(int i = 0; i< num; i++)
    {
        printf("Arr[%d]: %d\n", i+1, *(pt+i));
    }
}
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void arr_increase(int* pt, int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 00; j<num-i-1; j++)
        {
            if(*(pt+j) > *(pt+j+1))
            {
                swap((pt+j), (pt+j+1));
            }
        }
    }
}

void arr_decrease(int* pt, int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 00; j<num-i-1; j++)
        {
            if(*(pt+j) < *(pt+j+1))
            {
                swap((pt+j), (pt+j+1));
            }
        }
    }
}
int main()
{
    int arr[100];
    int num;
    Arr_get(arr, &num);
    arr_increase(arr, num);
    Arr_Print(arr, num);
    arr_decrease(arr, num);
    Arr_Print(arr, num);
    return 0;
}