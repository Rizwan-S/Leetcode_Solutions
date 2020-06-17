/*   https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if(!root) return NULL;
    if(root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p, q);
    if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}
