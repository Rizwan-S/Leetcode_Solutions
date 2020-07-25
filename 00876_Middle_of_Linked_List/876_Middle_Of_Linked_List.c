
/*	https://leetcode.com/problems/middle-of-the-linked-list/	*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    if(!head) return head;
    struct ListNode* fast = head, *slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}














