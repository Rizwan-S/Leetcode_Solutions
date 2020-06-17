/*  https://leetcode.com/problems/remove-linked-list-elements/  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    for (struct ListNode **curr = &head; *curr; ) 
    {
        struct ListNode *entry = *curr;
        if (entry->val == val) *curr = entry->next;
        else curr = &entry->next;
    }
    return head;
}
