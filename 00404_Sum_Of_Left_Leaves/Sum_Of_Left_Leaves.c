/*   https://leetcode.com/problems/sum-of-left-leaves/   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;
    
    if (root->left && !root->left->left && !root->left->right) {
        return root->left->val + sumOfLeftLeaves(root->right);
    } else {
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}
