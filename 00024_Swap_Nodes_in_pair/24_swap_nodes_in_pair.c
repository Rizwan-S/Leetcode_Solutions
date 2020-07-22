/*	https://leetcode.com/problems/swap-nodes-in-pairs/	*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next)
        return head;
    struct ListNode *Cur = head;
    int temp = Cur->val;
    Cur->val = Cur->next->val;
    Cur->next->val = temp;
    swapPairs(Cur->next->next);
    
    return head;
}