#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#if RECUR
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root)
        return NULL;
    if (root->val > val)
        return searchBST(root->left, val);
    if (root->val < val)
        return searchBST(root->right, val);
    return root;
}
#else
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    struct TreeNode *np = root;
    while (np)
    {
        if (np->val == val)
            return np;
        else if (np->val > val)
            np = np->left;
        else
            np = np->right;
    }
    return NULL;
}
#endif
