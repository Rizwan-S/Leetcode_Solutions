/*      https://leetcode.com/problems/maximum-depth-of-binary-tree/     */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxDepth(struct TreeNode* root)
{
    if(!root) return 0;
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    return max(left, right); 
}
