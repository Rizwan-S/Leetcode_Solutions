/*  https://leetcode.com/problems/majority-element/  */

int majorityElement(int* nums, int numsSize)
{   
    int cnt = 0, res;
    for (int i = 0; i < numsSize; ++i) 
    {
        if (cnt == 0) res = nums[i];
        if (res == nums[i]) cnt++;
        else cnt--;
    }
    return res;
}
