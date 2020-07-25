/*	https://leetcode.com/problems/two-sum/	*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int * const a, int * const b) 
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition_indexes(const int* const nums, int* const indexes, int lo, int hi) 
{
  int pivot = lo++;
  int pivot_val = nums[indexes[pivot]];
  int idx = pivot;
  int tmp;
  for (; lo < hi; ++lo) 
  {
    if (nums[indexes[lo]] <= pivot_val)
    {
      swap(indexes + lo, indexes + ++idx);
    }
  }
  swap(indexes + pivot, indexes + idx);
  return idx;
}

void sort_indexes(const int* const nums, int* const indexes, int lo, int hi) 
{
  if (lo < hi) 
  {
    int pivot = partition_indexes(nums, indexes, lo, hi);
    sort_indexes(nums, indexes, lo, pivot);
    sort_indexes(nums, indexes, pivot + 1, hi);
  }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
  int* ret = (int*)malloc(2 * sizeof(int));
  int* indexes = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) 
  {
    indexes[i] = i;
  }
  sort_indexes(nums, indexes, 0, numsSize);
  int lo = 0;
  int hi = numsSize - 1;
  while (nums[indexes[lo]] + nums[indexes[hi]] != target) 
  {
    if (nums[indexes[lo]] + nums[indexes[hi]] < target) 
    {
      ++lo;
    } else 
    {
      --hi;
    }
  }
  
  ret[0] = indexes[lo];
  ret[1] = indexes[hi];
  
  free(indexes);

  *returnSize = 2;
  return ret;
}