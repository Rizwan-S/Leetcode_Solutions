/*    https://leetcode.com/problems/longest-univalue-path/    */

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
    return a > b ? a : b;
}

int length(struct TreeNode* node, int* ans)
{
    if(!node) return 0;
    int left = length(node->left, ans);
    int right = length(node->right, ans);
    int Leftmax = 0, Rightmax = 0;
    if(node->left && node->left->val == node->val) Leftmax += left + 1;
    if(node->right && node->right->val == node->val) Rightmax += right + 1;
    *ans = max(*ans, Leftmax + Rightmax);
    return max(Leftmax, Rightmax);
}

int longestUnivaluePath(struct TreeNode* root)
{
    int ans = 0;
    length(root, &ans);
    return ans;
}
