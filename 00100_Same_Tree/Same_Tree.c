/*   https://leetcode.com/problems/same-tree/   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(!p && !q) return true;
    else if(!p && q) return false;
    else if(p && !q) return false;
    struct TreeNode** queue1 = (struct TreeNode*)malloc(10000*sizeof(struct TreeNode));
    struct TreeNode** queue2 = (struct TreeNode*)malloc(10000*sizeof(struct TreeNode));
    int head1 = 0, head2 = 0, tail1 = -1, tail2 = -1;
    queue1[++tail1] = p;
    queue2[++tail2] = q;
    struct TreeNode* temp1, *temp2;
    while(head1 <= tail1 && head2 <= tail2)
    {
        temp1 = queue1[head1++];
        temp2 = queue2[head2++];
        if(temp1 && temp2)
        {
            if(temp1->val != temp2->val) return false;
        }
        else if(temp1 && !temp2) return false;
        else if(!temp1 && temp2) return false;
        if(temp1)
        {
            queue1[++tail1] = temp1->left;
            queue1[++tail1] = temp1->right;
        }
        if(temp2)
        {
            queue2[++tail2] = temp2->left;
            queue2[++tail2] = temp2->right;
        }
    }
    if(tail1 == tail2) return true;
    return false;
}
