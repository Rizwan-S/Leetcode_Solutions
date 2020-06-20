/*  https://leetcode.com/problems/validate-binary-search-tree/   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool find(struct TreeNode* node, struct TreeNode** prev)
{
    if(node)
    {
        if(!find(node->left, prev)) return false;
        find(node->left, prev);
        if(*prev)
        {
            if(node->val <= (*prev)->val) return false;
        }
        *prev = node;
        return find(node->right, prev);
    }
    return true;
}


bool isValidBST(struct TreeNode* root)
{
    struct TreeNode* prev;
    prev = NULL;
    if(find(root, &prev)) return true;
    return false;
    
}
