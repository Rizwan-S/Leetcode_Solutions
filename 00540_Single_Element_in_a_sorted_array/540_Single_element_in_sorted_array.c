/*	https://leetcode.com/problems/single-element-in-a-sorted-array/	*/

int singleNonDuplicate(int* nums, int numsSize)
{
    int n = numsSize, l = 0, h = numsSize / 2;
    while(l < h)
    {
        int m = (l + h) / 2;
        if(nums[2*m] != nums[2*m + 1]) h = m;
        else l = m + 1;
    }
    return nums[2*l];
}
