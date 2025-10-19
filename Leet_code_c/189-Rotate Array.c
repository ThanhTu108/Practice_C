#include <stdio.h>

void reverse_arr(int* nums, int l, int r)
{
    while(l < r)
    {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
}

void rotate(int* nums, int numsSize, int k) 
{
    if(numsSize < 2) return;
    if(k == 0) return;
    k = k % numsSize;
    reverse_arr(nums, 0, numsSize - 1);
    reverse_arr(nums, 0 , k - 1);
    reverse_arr(nums, k, numsSize - 1);
}
int main()
{
    int arr[] = {1,2};
    rotate(arr, sizeof(arr)/sizeof(int), 1);
    for(int i = 0;i < (sizeof(arr)/sizeof(int)); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}