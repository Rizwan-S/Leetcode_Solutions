/*	https://leetcode.com/problems/reverse-linked-list/	*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    if(!head) return head;
    struct ListNode* current = head, *prev = NULL, *ahead;
    if(head->next) ahead = head->next;
    else return head;
    while(current)
    {
        current->next = prev;
        prev = current;
        current = ahead;
        if(ahead) ahead = ahead->next;
    }
    return prev;
}
