#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef enum
{
    false,
    true
} bool;

bool hasPathSum(struct TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    int currSum = 0;
    currSum = root->val;
    if (currSum == targetSum && !root->left && !root->right)
        return true;
    struct TreeNode **stack = malloc(sizeof(struct TreeNode *) * 100);
    int *sum = malloc(sizeof(int) * 100);
    int stackTop = -1;
    int sumTop = -1;
    stack[++stackTop] = root;
    sum[++sumTop] = currSum;
    root = root->left;
    int done = 0;
    while (!done)
    {
        while (root)
        {
            sum[++sumTop] = root->val + currSum;
            if (sum[sumTop] == targetSum && !root->left && !root->right)
                return true;
            else
            {
                stack[++stackTop] = root;
                currSum = sum[sumTop];
                root = root->left;
            }
        }
        if (stackTop >= 0)
        {
            root = stack[stackTop--];
            currSum = sum[sumTop--];
            root = root->right;
        }
        else
        {
            done = 1;
        }
    }
    free(sum);
    free(stack);
    return false;
}
