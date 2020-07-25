/*	https://leetcode.com/problems/linked-list-cycle/	*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL)
    {
        return 0;
    }
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(slow && fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            return 1;
    }
    return 0;
}


