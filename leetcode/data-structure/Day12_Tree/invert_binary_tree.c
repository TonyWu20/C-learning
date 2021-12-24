#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#if RECUR
struct TreeNode *invertTree(struct TreeNode *root)
{
    if (!root)
        return NULL;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    return root;
}
#else
struct TreeNode *invertTree(struct TreeNode *root)
{
    if (!root)
        return NULL;
    struct TreeNode **stack = malloc(sizeof(struct TreeNode *) * 1000);
    int stackCount = 0;
    while (root)
    {
        if (root->right)
            stack[stackCount++] = root->right;
        if ((root->right) || (root->left))
        {
            struct TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        root = root->right;
        if (!root && stackCount > 0)
        {
            root = stack[--stackCount];
        }
    }
    free(stack);
    return root;
}
#endif
