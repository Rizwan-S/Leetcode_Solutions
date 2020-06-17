/*  https://leetcode.com/problems/single-number/  */

int singleNumber(int* nums, int numsSize)
{
    int n = 0;
    for(int i = 0; i < numsSize; i++)
    {
        n ^= nums[i];
    }
    return n;
}
