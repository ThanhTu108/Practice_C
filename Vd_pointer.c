#include <stdio.h>
//using pointer to scan array from keyboard (10 element)
//using pointer to arrange array from small to large
void Arr_get(int arr[], int* number)
{
    printf("Enter number of array: ");
    scanf("%d", number);
    int* pt = arr;
    for(int i = 0; i<*number; i++)
    {
        printf("Enter %d elements: ", i+1);
        scanf("%d", pt+i);
    }
}
void Arr_print(int arr[], int number)
{
    int* pt = arr;
    for (int i = 0; i < number; i++)
    {
        printf("Phan tu thu %d: %d\n", i+1, *(pt+i));
    }
}
void swap_arr(int*a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Arr_arrange(int arr[], int number)
{
    int* pt = arr;
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number-i-1; j++)
        {
            if(*(pt + j) > *(pt+j+1))
            {
                swap_arr((pt+j), (pt+j+1));
            }
        }
    }
}

// void Arr_
int main()
{
    int arr[100];
    int num = 0;
    Arr_get(arr, &num);
    Arr_arrange(arr, num);
    Arr_print(arr, num);
    return 0;
}