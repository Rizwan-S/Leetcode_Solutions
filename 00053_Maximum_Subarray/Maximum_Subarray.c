/*     https://leetcode.com/problems/maximum-subarray/    */

int maxSubArray(int* nums, int numsSize)
{
    if (numsSize == 0) return -2147483648;
    int msf = -2147483648;
    int meh = 0;
    for(int i = 0; i < numsSize; i++)
    {
        meh += nums[i];
        if(msf < meh) msf = meh;      
        if(meh < 0) meh = 0;
    }
    return msf;
}
