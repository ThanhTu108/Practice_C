#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int j = 0;
    for(int i = 1; i<numsSize; i++)
    {
        if(nums[i] != nums[j])
        {
            j++;
            nums[j] = nums[i];
        }
    }
    return j+1;
}

int main()
{

    int arr[] = {1, 1, 2};
    int newSize = removeDuplicates(arr, sizeof(arr)/sizeof(int));
    printf("newSize = %d\n", newSize);
    for(int i = 0;i < newSize; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}