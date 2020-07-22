/*	https://leetcode.com/problems/cousins-in-binary-tree/		*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isCousins(struct TreeNode* root, int x, int y)
{
    int bool1 = false, bool2 = false;
    int Phi[101], V[101], L[101], head = -1, tail = 0;
    for(int i = 0; i < 100; i++)
    {
        Phi[i] = -2;
        V[i] = 0;
        L[i] = INT_MAX;
    }
    struct TreeNode* queue[101];
    queue[++head] = root;
    Phi[root->val] = -1;
    V[root->val] = 1;
    L[root->val] = 0;
    while(head >= tail)
    {
        struct TreeNode* u = queue[tail++];
        if(u->val == x) bool1 = true;
        if(u->val == y) bool2 = true;
        if(bool1 && bool2) break;
        if(u->left)
        {
            if(V[u->left->val] == 0)
            {
                queue[++head] = u->left;
                Phi[u->left->val] = u->val;
                V[u->left->val] = 1;
                L[u->left->val] = L[u->val] + 1;
            }
        }
        if(u->right)
        {
            if(V[u->right->val] == 0)
            {
                queue[++head] = u->right;
                Phi[u->right->val] = u->val;
                V[u->right->val] = 1;
                L[u->right->val] = L[u->val] + 1;
            }
        }
    }
    if(L[x] == L[y])
    {
        if(Phi[x] != Phi[y])
        {
            return true;   
        }
    }
    return false;     
}