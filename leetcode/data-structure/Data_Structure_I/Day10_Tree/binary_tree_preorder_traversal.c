#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    struct TreeNode **stack = calloc(1, sizeof(struct TreeNode *));
    struct TreeNode *head = root;
    int stackTop = -1;
    int temp[100];
    int elmCount = 0;
    while (head)
    {
        while (head)
        {
            temp[elmCount++] = head->val;
            if (head->right)
            {
                stack[++stackTop] = head->right;
                stack =
                    realloc(stack, (stackTop + 2) * sizeof(struct TreeNode *));
            }
            head = head->left;
        }
        if (stackTop > -1)
        {
            head = stack[stackTop];
            stack[stackTop--] = NULL;
        }
    }
    int *ret = malloc(sizeof(int) * elmCount);
    memcpy(ret, temp, sizeof(int) * elmCount);
    free(stack);
    *returnSize = elmCount;
    return ret;
}
