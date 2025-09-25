#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int* arr, int num)
{
    int left = 0, right = num-1;
    while(left < right)
    {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
}
int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    reverse(arr, num);

    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
