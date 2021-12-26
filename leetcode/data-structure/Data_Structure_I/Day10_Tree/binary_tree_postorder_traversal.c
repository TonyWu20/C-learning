#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void pushNode(struct TreeNode ***stack, struct TreeNode *np, int *stackTop)
{
    *stack = realloc(*stack, sizeof(struct TreeNode *) * (*stackTop + 3));
    (*stackTop) += 2;
    (*stack)[*stackTop - 1] = np;
    (*stack)[*stackTop] = np;
}
int *postOrderTraversal(struct TreeNode *root, int *returnSize)
{
    struct TreeNode **stack = NULL;
    int stackTop = -1;
    int *result = NULL;
    int resultLen = 0;
    struct TreeNode *np = root;
    pushNode(&stack, np, &stackTop);
    np = np->left;
    while (stackTop > -1)
    {
        while (np)
        {
            pushNode(&stack, np, &stackTop);
            np = np->left;
        }
        np = stack[stackTop--];
        if (np == stack[stackTop])
        {
            np = np->right;
        }
        else
        {
            result = realloc(result, sizeof(int) * (++resultLen + 1));
            result[resultLen - 1] = np->val;
            np = NULL;
        }
    }
    free(stack);
    *returnSize = resultLen;
    return result;
}
