#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) 
{
    int j = 2;
    if(numsSize <= 2)
    {
        return numsSize;
    }
    for(int i = 2; i<numsSize; i++)
    {
        if(nums[i]!=nums[j - 2])
        {
            nums[j] = nums[i];
            j++;
        }
    }  
    return j;  
}


int main()
{
    int arr[] = {1, 1, 1, 1, 2};
    int newSize = removeDuplicates(arr, sizeof(arr)/sizeof(int));
    printf("newSize = %d\n", newSize);
    for(int i = 0;i < newSize; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}