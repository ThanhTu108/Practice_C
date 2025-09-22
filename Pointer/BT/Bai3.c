#include <stdio.h>

void Arr_Get(int* pt, int* num)
{
    printf("Enter number: ");
    scanf("%d", num);
    for(int i = 0; i < *num; i++)
    {
        printf("Arr[%d]: ", i+1);
        scanf("%d", (pt+i));
    }
}

void Arr_Print(int* pt, int num)
{
    printf(".................\n");
    for(int i = 0; i< num; i++)
    {
        printf("Arr[%d]: %d\n",i+1, *(pt+i));
    }
}
int* sum_arr(int* pt, int num)
{
    static int sum;
    sum = 0;
    for(int i = 0;i < num; i++)
    {
        sum+=*(pt+i);
    }
    return &sum;
}
int main()
{
    int arr[100];
    int num;
    int* res;
    int* res_2;
    Arr_Get(arr, &num);
    res = sum_arr(arr, num);
    res_2 = sum_arr(arr, num);
    printf("Sum array: %d\n", *res);
    printf("Sum array: %d\n", *res_2);
    Arr_Print(arr, num);
    return 0;
}