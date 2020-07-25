
/*	https://leetcode.com/problems/symmetric-tree/	*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool symt(struct TreeNode* root1, struct TreeNode* root2)
{
    if(!root1 && !root2) return true;
    if(root1 && root2 && root1->val == root2->val)
    {
        return symt(root1->left, root2->right) && symt(root1->right, root2->left);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    return symt(root, root);
}