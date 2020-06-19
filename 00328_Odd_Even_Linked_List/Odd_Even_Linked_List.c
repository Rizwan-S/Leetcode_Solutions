/*    https://leetcode.com/problems/odd-even-linked-list/     */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head)
{
    if(!head) return NULL;
    struct ListNode *odd = head, *even = head->next, *evenhead = even;
    while(even && even->next)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}
