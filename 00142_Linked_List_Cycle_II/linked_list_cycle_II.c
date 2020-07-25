/*	https://leetcode.com/problems/linked-list-cycle-ii/	*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    if (head == NULL || head->next == NULL) return NULL;
    struct ListNode *slow  = head;
    struct ListNode *fast  = head;
    struct ListNode *entry = head;
    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {                     
            while(slow != entry) 
            {              
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;                                 
}