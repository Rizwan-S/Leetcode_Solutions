/*    https://leetcode.com/problems/intersection-of-two-arrays/   */

int cmpfunc(int* a, int* b)
{
    return *a - *b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i=0,j=0,idx=0,len;
    int* result = NULL;
    
    qsort(nums1,nums1Size,sizeof(int),cmpfunc);
    qsort(nums2,nums2Size,sizeof(int),cmpfunc);
    
    len = (nums1Size>nums2Size)?nums2Size:nums1Size;
    
    result = (int*)malloc(len*sizeof(int));
    
    while(i<nums1Size && j<nums2Size)
    {
        while(i<nums1Size-1 && nums1[i]==nums1[i+1])
            i++;
        while(j<nums2Size-1 && nums2[j]==nums2[j+1])
            j++;
        
        if(nums1[i] < nums2[j])
        {
            i++;
        }
        else if(nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            result[idx++] = nums1[i];
            i++;
            j++;
        }
    }
    
    *returnSize = idx;
    return result;
}
