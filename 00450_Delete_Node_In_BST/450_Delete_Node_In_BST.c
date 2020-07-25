
/*	https://leetcode.com/problems/delete-node-in-a-bst/	*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if(!root) return root;
    if(root->val < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    else if(root->val > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if(root->left &&  root->right)
    {
        struct TreeNode* temp = root->left;
        while(temp->right) temp = temp->right;
        root->val = temp->val;
        root->left = deleteNode(root->left, temp->val);
    }
    else
    {
        struct TreeNode* child;
        if(!root->left) child = root->right;
        else child = root->left;
        free(root);
        return child; 
    }
    return root;
}












