/*	https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/	*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newnode(int key)
{
    struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->left = new->right = NULL;
    new->val = key;
    return new;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    struct TreeNode* root = newnode(preorder[0]);
    struct TreeNode* temp;
    for(int i = 1; i < preorderSize; i++)
    {
        temp = root;
        while(temp)
        {
            if(temp->val > preorder[i])
            {
                if(temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newnode(preorder[i]);
                    break;
                }
            }
            else
            {
                if(temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = newnode(preorder[i]);
                    break;
                }
            }
        }
    }
    return root;
}

