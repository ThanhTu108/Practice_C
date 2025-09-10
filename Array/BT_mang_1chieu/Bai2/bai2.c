#include <stdio.h>

void enter_array(int arr[], int* number_array)
{
    printf("Enter number of array: ");
    scanf("%d", number_array);
    printf("Enter value array\n");
    for (int i = 0; i< *number_array; i++)
    {
        printf("arr[%d]: ", i);
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
void find_min(int arr[], int number_array)
{
    int min = arr[0];
    for (int i = 0;i < number_array; i++)
    {
        if(min < arr[i])
        {
            min = arr[i];
        }
    }
    printf("Min: %d\n", min);
}
int main()
{
    int arr[100];
    int n = 0;
    enter_array(arr, &n);
    find_min(arr, n);
    print_array(arr, n);
    return 0;
}