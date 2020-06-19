/*   https://leetcode.com/problems/binary-tree-preorder-traversal/   */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode *stack[10000];
    int top = -1;
    int* trav = (int*)malloc(10000*sizeof(int));
    *returnSize = 0;
    if(root)
    {
        stack[++top] = root;
        while(top >= 0)
        {
            trav[*returnSize] = stack[top]->val;
            *returnSize += 1;
            root = stack[top--];
            if(root->right) stack[++top] = root->right;
            if(root->left) stack[++top] = root->left;
        }

    }
    return trav;
}
