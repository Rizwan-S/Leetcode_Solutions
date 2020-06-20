/*    https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/  */


int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int* out = (int*)malloc(2*sizeof(int));
    if(numsSize == 0)
    {
        *returnSize = 2;
        out[0] = out[1] = -1;
        return out;
    }
	int min, max, current = -1, currentmax = -1;
	*returnSize = 2;
	int l = 0, r = numsSize;
	int mid;
	while(l <= r)
	{
        if(l == numsSize) break;
		mid = (l + r) / 2;
		if(target == nums[mid])
		{
			current = mid;
			break;
		}
		else
		{
			if(nums[mid] < target) l = mid + 1;
			else if(nums[mid] > target) r = mid - 1;
		}
	}
	if(current == -1) 
	{
		out[0] = out[1] = -1;
		return out;
	}

	currentmax = min = max = current;
	l = 0; 
	r = current;
	while(current != -1)
	{
		if(l < r)
		{
			mid = (l + r) / 2;
			if(target == nums[mid])
			{
				min = mid;
				r = mid;
			}
			else
			{
				if(nums[mid] < target) l = mid + 1;
				else if(nums[mid] > target) r = mid - 1;
			}
		}
		else current = -1;
	}
	l = currentmax + 1;
	r = numsSize;

	while(currentmax != -1)
	{
		if(l <= r)
		{
            if(l == numsSize) break;
			mid = (l + r) / 2;
			if(target == nums[mid])
			{
				max = mid;
				l = mid + 1;
			}
			else
			{
				if(nums[mid] < target) l = mid + 1;
				else if(nums[mid] > target) r = mid - 1;
			}
		}
		else currentmax = -1;
	}
	out[0] = min;
	out[1] = max;
	return out;
}
