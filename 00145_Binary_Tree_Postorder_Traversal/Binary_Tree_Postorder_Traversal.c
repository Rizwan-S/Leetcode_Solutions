/*  https://leetcode.com/problems/binary-tree-postorder-traversal/  */

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
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode *stack[10000];
    bool base[10000];
    int top = -1;
    int* trav = (int*)malloc(10000*sizeof(int));
    *returnSize = 0;
    if(root)
    {
        stack[++top] = root;
        base[top] = false;
        while(top >= 0)
        {
            if(base[top] == true)
            {
                trav[*returnSize] = stack[top--]->val; 
                *returnSize += 1;
            }
            else
            {
                root = stack[top];
                base[top] = true;
                if(root->right)
                {
                    stack[++top] = root->right;
                    base[top] = false;
                }
                if(root->left)
                {
                    stack[++top] = root->left;
                    base[top] = false;
                }
            }
        }
    }
    return trav;
}


