/*  https://leetcode.com/problems/rotate-list/  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head == NULL) return head;
    struct ListNode * tail = head;
    int len = 0;
    while(tail->next != NULL) 
    {
        len++;
        tail = tail->next;
    }
    while(k > len) k = k - len - 1;
    for(int i = 0; i < len - k + 1; i++)
    {
        tail->next = head;
        head = head->next;
        tail = tail->next;
        tail->next = NULL;
    }
    return head;
}
