#include <stdlib.h>
#include <string.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lDep = maxDepth(root->left);
    int rDep = maxDepth(root->right);
    return (lDep > rDep) ? lDep + 1 : rDep + 1;
}

void helper(struct TreeNode *root, int sum, int *cur, int curS, int **colS,
            int *retS, int **ret)
{
    if (root->val == sum && !root->left && !root->right)
    {
        ret[*retS] = malloc(sizeof(int) * (curS + 1));
        memcpy(ret[*retS], cur, sizeof(int) * curS);
        ret[*retS][curS] = root->val;
        (*colS)[*retS] = curS + 1;
        (*retS)++;
        return;
    }
    cur[curS] = root->val;
    if (root->left)
        helper(root->left, sum - cur[curS], cur, curS + 1, colS, retS, ret);
    if (root->right)
        helper(root->right, sum - cur[curS], cur, curS + 1, colS, retS, ret);
}

int **pathSum(struct TreeNode *root, int targetSum, int *returnSize,
              int **returnColumnSizes)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    *returnColumnSizes = malloc(sizeof(int) * 500);
    int **ret = malloc(sizeof(int *) * 500);
    int cur[maxDepth(root)];
    helper(root, targetSum, cur, 0, returnColumnSizes, returnSize, ret);
    return ret;
}
