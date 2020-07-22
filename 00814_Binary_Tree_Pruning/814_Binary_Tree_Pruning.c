/*	https://leetcode.com/problems/binary-tree-pruning/	*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



struct TreeNode* pruneTree(struct TreeNode* root) {
    if (!root) return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return (!root->val && !root->left && !root->right) ? NULL : root;
}