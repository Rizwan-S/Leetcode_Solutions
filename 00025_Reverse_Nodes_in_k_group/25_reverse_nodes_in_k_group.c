/*	https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/		*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rearrangearray(int a[], int n)
{
    for(int i = 0; i < n / 2; i++)
    {
        swap(&a[i], &a[n - i - 1]);
    }
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    int temp = 0;
    int a[k]; 
    struct ListNode* c = head, *p = head;
    while(c)
    {
        a[temp] = c->val;
        c = c->next;
        temp++;
        if(temp == k)
        {
            rearrangearray(a, temp);
            for(int i = 0; i < temp; i++) printf("%d ", a[i]);
            for(int i = 0; i < temp; i++)
            {
                p->val = a[i];
                p = p->next;
            }
            temp = 0;
        }
    }
    return head;
}
