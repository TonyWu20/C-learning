#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int recur_find(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q,
               struct TreeNode **lca)
{
    if (!root)
        return 0;
    int left, right, mid;
    left = (recur_find(root->left, p, q, lca)) ? 1 : 0;
    right = (recur_find(root->right, p, q, lca)) ? 1 : 0;
    mid = (root == p || root == q) ? 1 : 0;
    if (mid + left + right >= 2)
    {
        *lca = root;
    }
    return (mid + left + right > 0);
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p,
                                      struct TreeNode *q)
{
    struct TreeNode *lca = NULL;
    recur_find(root, p, q, &lca);
    return lca;
}
