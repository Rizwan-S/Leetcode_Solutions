/*  https://leetcode.com/problems/merge-two-sorted-lists/  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) 
{
    
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;   
    struct ListNode* head = NULL;   
    if(l1->val < l2->val)       
    {
        head = l1; 
        l1 = l1->next; 
    }
    else
    { 
        head = l2; 
        l2 = l2->next; 
    }
    struct ListNode* p = head;  
    while(l1 && l2)
    {
        if(l1->val < l2->val)   
        { 
            p->next = l1; 
            l1 = l1->next;
        }
        else                   
        { 
            p->next = l2;
            l2 = l2->next; 
        }
        p=p->next;
    }
    if(l1)  p->next=l1;
    else    p->next=l2;
    return head;
}
