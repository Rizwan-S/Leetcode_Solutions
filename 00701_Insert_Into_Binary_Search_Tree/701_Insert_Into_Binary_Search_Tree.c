/*	https://leetcode.com/problems/insert-into-a-binary-search-tree/	*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* Newnode(int key)
{
    struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->left = newnode->right = NULL;
    newnode->val = key;
    return newnode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if(!root) return Newnode(val);
    struct TreeNode* current = root;
    while(current)
    {
        if(val > current->val)
        {
            if(current->right) current = current->right;
            else
            {
                current->right = Newnode(val);
                break;
            }
        }
        else
        {
            if(current->left) current = current->left;
            else
            {
                current->left = Newnode(val);
                break;
            }
            
        }
    }
    return root;
}
