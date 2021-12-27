#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#if RECUR
struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (!root)
    {
        root = malloc(sizeof(struct TreeNode));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return NULL;
}
#else
struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (!root)
    {
        root = malloc(sizeof(struct TreeNode));
        root->val = val;
        root->left = root->right = NULL;
        return root;
    }
    struct TreeNode *np = root;
    while (np)
    {
        if (np->val > val && np->left)
            np = np->left;
        else if (np->val < val && np->right)
            np = np->right;
        else
            break;
    }
    struct TreeNode *new;
    new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = new->right = NULL;
    if (np->val > val)
        np->left = new;
    else
        np->right = new;
    return root;
}
#endif
