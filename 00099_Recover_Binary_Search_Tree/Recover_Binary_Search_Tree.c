/*    https://leetcode.com/problems/recover-binary-search-tree/   */

void traverse(struct TreeNode* root, struct TreeNode** pre, struct TreeNode** first, struct TreeNode** second)
{
    if(!root) return ;
    traverse(root->left, pre, first, second);
    if((*pre) && (*pre)->val>root->val)
    {
        if(!(*first))  
            *first=*pre; 
        *second = root;
    }
    *pre = root;
    traverse(root->right, pre, first, second);
}


void recoverTree(struct TreeNode* root)
{
    struct TreeNode *first=NULL, *second=NULL, *pre=NULL;
    traverse(root, &pre, &first, &second);
    if(first&&second)
    {
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
}
