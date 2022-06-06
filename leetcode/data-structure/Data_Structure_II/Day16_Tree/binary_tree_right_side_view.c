#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode *root, int level, int *maxLevel, int *arr,
              int *arrCount)
{
    if (!root)
        return;
    if (*maxLevel < level)
    {
        arr[(*arrCount)++] = root->val;
        *maxLevel = level;
    }
    traverse(root->right, level + 1, maxLevel, arr, arrCount);
    traverse(root->left, level + 1, maxLevel, arr, arrCount);
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int arr[100];
    int arrCount = 0;
    int maxLevel = -1;
    traverse(root, 0, &maxLevel, arr, &arrCount);
    *returnSize = arrCount;
    int *ret = malloc(sizeof(int) * arrCount);
    for (int i = 0; i < arrCount; ++i)
        ret[i] = arr[i];
    return ret;
}
