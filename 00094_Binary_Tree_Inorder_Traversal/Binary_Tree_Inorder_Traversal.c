/*  https://leetcode.com/problems/binary-tree-inorder-traversal/  */

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
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root)
    {
        struct TreeNode* stack[100000];
        bool base[100000];
        int top = -1;
        int *trav = (int*)malloc(100000*sizeof(int));
        *returnSize = 0;
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
                root = stack[top--];
                if(root->right)
                {
                    stack[++top] = root->right;
                    base[top] = false;
                }
                stack[++top] = root;
                base[top] = true;
                if(root->left)
                {
                    stack[++top] = root->left;
                    base[top] = false;
                }
            }
        }
        return trav;
    }
    *returnSize = 0;
    int a[1];
    return a;
    
}



