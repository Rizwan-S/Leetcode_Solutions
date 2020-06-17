/*    https://leetcode.com/problems/remove-nth-node-from-end-of-list/   */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(!head) return NULL;
    if(!head->next) return NULL;
    struct ListNode* p = head;
    int len = 0;
    while(p->next)
    {
        len++;
        p = p->next;
    }
    len++;
    p = head;
    len = len - n;
    if(len == 0) 
    {
        head = head->next;
        free(p);
    }
    else
    {
        for(int i = 0; i < len - 1; i++)
        {
            p = p->next;
        }
        struct ListNode* temp = p->next;
        if(temp->next)
        {
            p->next = p->next->next;
            free(temp);
        }
        else
        {
            p->next = NULL;
            free(temp);
        }
    }
    return head;
}
