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

void Arr_print(int* pt, int num)
{
    printf("...........\n");
    for(int i = 0; i<num; i++)
    {
        printf("Arr[%d]: %d\n", i+1, *(pt+i));
    }
}
void arr_remove_target(int* pt, int* num, int target)
{
    int temp = 0;
    for(int i = 0; i<*num; i++)
    {
        if(pt[i] != target)
        {
            pt[temp++] = pt[i];
        }
    }
    *num = temp;
}
void Arr_print_reverse(int* pt, int num)
{
    printf("...........\n");
    for(int i = num-1; i>=0; i--)
    {
        printf("Arr[%d]: %d\n", i+1, *(pt+i));
    }
}

void arr_reverse(int* pt, int num)
{
    int left = 0, right = num - 1;
    while(left < right)
    {
        int temp;
        temp = pt[left];
        pt[left] = pt[right];
        pt[right] = temp;
        left++;
        right--;
    }
}


int main()
{
    int arr[100];
    int num;
    Arr_get(arr, &num);
    arr_remove_target(arr, &num, 4);
    arr_reverse(arr, num);
    
    Arr_print(arr, num);
    
    return 0;
}