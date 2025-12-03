#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) 
{
    int j = 0;
    for(int i = 0;i<numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    } 
    return j;  
}
int main()
{
    int arr[] = {3,2,2,3};
    int newSize = removeElement(arr, sizeof(arr) /sizeof(int), 2);
    printf("%d", newSize);
}