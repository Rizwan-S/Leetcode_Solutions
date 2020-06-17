/*  https://leetcode.com/problems/remove-duplicates-from-sorted-array/   */

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 1) return 1;
    if(numsSize == 0) return 0;
    int i = 0, j = 1;
    while(j < numsSize)
    {
        if(nums[j] != nums[i])
        {
            nums[++i] = nums[j];
        }
        j++;
    }
    return i + 1;
}
