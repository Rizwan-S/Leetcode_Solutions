/*	https://leetcode.com/problems/kth-smallest-element-in-a-bst/		*/

int ans = 0;

void fun(struct TreeNode* root, int k, int *idx)
{
    if(!root) return;
    fun(root->left, k, idx);
    if (*idx == k) ans = root->val;
    (*idx)++;
    fun(root->right, k, idx);
}

int kthSmallest(struct TreeNode* root, int k) {
    int idx = 1;
    fun(root, k, &idx);
    return ans;
}

