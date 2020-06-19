/*  https://leetcode.com/problems/kth-largest-element-in-an-array/   */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bottomupheapify(int i, int heap[])
{
	int p = (i - 1) / 2;
	while(p >= 0 && heap[p] < heap[i])
	{
		swap(&heap[p], &heap[i]);
		i = p;
		p = (i - 1) / 2;
	}
}

void topdownheapify(int i, int n, int heap[])
{
	int l;
	while(2*i + 2 < n)
	{
		l = (heap[2*i + 1] > heap[2*i + 2]) ? (2*i + 1) : (2*i + 2);
		if(heap[i] < heap[l])
		{
			swap(&heap[i], &heap[l]);
			i = l;
		}
		else break;
		if(2* i + 1 < n && heap[i] < heap[2*i + 1])
		{
			swap(&heap[i], &heap[2*i + 1]);
		}
	}
}

void buildheap(int heap[], int n)
{
	for(int i = 1; i < n; i++) bottomupheapify(i, heap);
}

void deletemax(int heap[], int n)
{
	int x = heap[0];
	heap[0] = heap[--n];
	heap[n] = x;
	topdownheapify(0, n, heap);
}

int findKthLargest(int* nums, int numsSize, int k)
{   
    buildheap(nums, numsSize);
    for(int i = numsSize; i > numsSize - k; i--)
    {
        buildheap(nums, i);
        deletemax(nums, i);
    }
    return nums[numsSize - k];
}
