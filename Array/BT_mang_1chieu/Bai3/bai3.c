#include <stdio.h>
void enter_array(int arr[], int* number_array)
{
    printf("Enter number of array: ");
    scanf("%d", number_array);
    printf("Enter value array \n");
    for (int i = 0; i < *number_array; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void print_array(int arr[], int number_array)
{
    printf("..............\n");
    for (int i = 0; i < number_array; i++)
    {
        printf("Array[%d]: %d\n", i, arr[i]);
    }
}
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort_array_increase(int arr[], int number_array)
{
    for (int i = 0; i< number_array; i++)
    {
        for (int j = 0; j < number_array - i -1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[100];
    int n = 0;
    enter_array(arr, &n);
    sort_array_increase(arr, n);
    print_array(arr, n);
    return 0;
}