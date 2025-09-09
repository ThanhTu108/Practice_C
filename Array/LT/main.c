#include <stdio.h>
#include <string.h>

void enter_array(int arr[], int* number_of_array)
{
    // number_of_array: address
    // *number_of_array: value

    printf("Enter number of array: ");
    scanf("%d", number_of_array);
    printf("Enter value array\n");
    for(int i = 0; i < *number_of_array; i++)
    {
        printf("Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void print_array(int arr[], int numer_of_array)
{
    printf("...............\n");
    for(int i = 0; i< numer_of_array; i++)
    {
        printf("Ayyar[%d]: %d \n", i, arr[i]);
    }
}
int find_prime(int n)
{
    if(n<2)
    {
        return 0;
    }
    for(int i = 2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void find_prime_array(int arr[], int number_of_array)
{
    printf("Prime: \n");
    for(int i =0; i < number_of_array; i++)
    {
        if (find_prime(arr[i])!=0)
        {
            printf("Prime arr[%d]: %d\n", i, arr[i]);
        }
    }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_increase(int arr[], int number_of_array)
{
    
    for(int i = 0; i<number_of_array; i++)
    {
        for(int j = 0; j< number_of_array - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void sort_reduce(int arr[], int number_of_array)
{
    
    for(int i = 0; i<number_of_array; i++)
    {
        for(int j = 0; j< number_of_array - i; j++)
        {
            if(arr[j] < arr[j+1])
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
    find_prime_array(arr, n);

    sort_increase(arr, n);
    print_array(arr, n);
    sort_reduce(arr, n);
    print_array(arr, n);
    return 0;
}