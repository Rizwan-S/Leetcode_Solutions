/*   https://leetcode.com/problems/remove-duplicates-from-sorted-list/   */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int key)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = key;
    node->next = NULL;
    return node;
}


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(!head) return NULL;
    struct ListNode* p1 = head;
    struct ListNode* p2 = newNode(head->val);
    struct ListNode* ans = p2;
    if(p1->next) p1 = p1->next;
    else return p2;
    while(p1)
    {
        if(p1->val != p2->val)
        {
            
            p2->next = newNode(p1->val);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return ans;
}

