#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int i = m - 1;
    int j = n - 1;
    int end_idx = m + n - 1;
    while(i>=0 && j >=0)
    {
        
        if(nums1[i] > nums2[j])
        {
            nums1[end_idx] = nums1[i];
            i--;
        }
        else
        {
            nums1[end_idx] = nums2[j];
            j--;
        }
        end_idx--;
    }
    while(j >= 0)
    {
        nums1[end_idx] = nums2[j];
        j--;
        end_idx--;
    }
}

int main() {
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);

    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }
    return 0;
}
