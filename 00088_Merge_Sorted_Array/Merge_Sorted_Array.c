/*  https://leetcode.com/problems/merge-sorted-array/  */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = m - 1, j = n - 1;
    int len = m + n - 1;
    while(i > -1 && j > -1)
    {
        if(nums1[i] >= nums2[j]) nums1[len--] = nums1[i--];
        else nums1[len--] = nums2[j--];
    }
    while(i > -1) nums1[len--] = nums1[i--];
    while(j > -1) nums1[len--] = nums2[j--];
}
