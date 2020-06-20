/*   https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/     */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newnode(int key)
{
    struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->val = key;
    new->left = new->right = NULL;
    return new;
}


struct TreeNode* Tree(int* nums, int i, int j)
{
    if(i > j) return NULL;
    int mid = (i + j) / 2;
    struct TreeNode *root = newnode(nums[mid]);
    root->left = Tree(nums, i, mid - 1);
    root->right = Tree(nums, mid + 1, j);
    return root;    
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return Tree(nums, 0, numsSize - 1);
}
