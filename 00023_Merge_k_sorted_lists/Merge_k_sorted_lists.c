/*  https://leetcode.com/problems/merge-k-sorted-lists/  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergesort(int a[], int l, int r)
{
	int mid = (l + r) / 2;
	if(l < r)
	{
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

struct ListNode* newnode(int key)
{
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = key;
    new->next = NULL;
    return new;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize == 0) return NULL;
    int* temparray = (int*)malloc(100000*sizeof(int));
    int head = 0;
    for(int i = 0; i < listsSize; i++)
    {
        struct ListNode* temp = lists[i];
        while(temp)
        {
            temparray[head++] = temp->val;
            temp = temp->next;
        }
    }
    if(head == 0) return NULL;
    mergesort(temparray, 0, head - 1);
    struct ListNode* ans = newnode(temparray[0]);
    struct ListNode* temp = ans;
    for(int i = 1; i < head; i++)
    {
        temp->next = newnode(temparray[i]);
        temp = temp->next;
    }
    return ans;
}
