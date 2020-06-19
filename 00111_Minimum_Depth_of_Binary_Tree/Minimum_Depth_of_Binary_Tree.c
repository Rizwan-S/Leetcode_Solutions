/*    https://leetcode.com/problems/minimum-depth-of-binary-tree/    */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a, int b)
{
    if(a < 0) return b;
    if(b < 0) return a;
    return (a < b) ? a : b;
}


int minDepth(struct TreeNode* root)
{
    int leftval = 0, rightval = 0;
    if(!root) return 0;
    else if(root->left && root->right)
    {
        leftval = minDepth(root->left) + 1;
        rightval = minDepth(root->right) + 1;
    }
    else if(!root->left && root->right) 
    {
        leftval = INT_MIN;
        rightval = minDepth(root->right) + 1;
    }
    else 
    {
        rightval = INT_MIN;
        leftval = minDepth(root->left) + 1;
    }
    return min(leftval, rightval); 
}
