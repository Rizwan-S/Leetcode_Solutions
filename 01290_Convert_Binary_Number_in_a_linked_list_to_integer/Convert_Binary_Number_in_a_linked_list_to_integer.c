/*    https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/    */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head)
{
    if(head == NULL) return 0;
	int ans = 0;
	while(head)
	{
		ans = (2*ans) + head->val;
		head = head->next;
	}
	return ans;
}
