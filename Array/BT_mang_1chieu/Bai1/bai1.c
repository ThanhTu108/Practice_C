#include <stdio.h>
#include <string.h>

void enter_array(int arr[], int* number_array)
{
    printf("Enter number of array: ");
    scanf("%d", number_array);
    printf("Enter value array\n");
    for(int i = 0; i< *number_array; i++)
    {
        printf("Arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void print_array(int arr[], int number_array)
{
    printf("...............\n");
    for(int i = 0; i < number_array; i++)
    {
        printf("Array[%d]: %d \n", i, arr[i]);
    }
}

void spilit_array(int arr[], int arr_a[], int arr_b[], int index_spilit, int number_array)
{
    for (int i = 0; i < index_spilit; i++)
    {
        arr_a[i] = arr[i];
    }
    for (int i = index_spilit; i < number_array; i++)
    {
        arr_b[i - index_spilit] = arr[i];
    }
}
void merge_array(int arr[], int arr_a[], int arr_b[], int size_a, int size_b)
{
    for (int i = 0; i < size_a; i++)
    {
        arr[i] = arr_a[i];
    }
     for (int i = 0; i < size_b; i++)
    {
        arr[size_a + i] = arr_b[i];
    }
}

int main()
{
    int arr[100], arr1[100], arr2[100], arr3[100];
    int n = 0;
    int spilit = 3;
    enter_array(arr, &n);
    spilit_array(arr, arr1, arr2, spilit, n);
    printf("Mang 1:\n");
    print_array(arr1, spilit);
    printf("Mang 2:\n");
    print_array(arr2, n - spilit);

    printf("Mang sau khi gop:\n");
    merge_array(arr3, arr1, arr2, spilit, n - spilit);
    print_array(arr3, n);
    return 0;
}