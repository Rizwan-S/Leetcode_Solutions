/*      https://leetcode.com/problems/path-sum/     */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int sum)
{
    if(root == NULL) return false;
    else
    {
        bool ans = false;
        int subsum = sum - root->val;
        if(subsum == 0 && root->left == NULL && root->right == NULL) return true;
        if(root->left) ans = ans || hasPathSum(root->left, subsum);
        if(root->right) ans = ans || hasPathSum(root->right, subsum);
        return ans;
    }
}

