#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int stackSize = 10;
    int retArrSize = 10;
    int stackTop = -1;
    int retPtr = -1;
    struct TreeNode **nodeStack = calloc(stackSize, sizeof(struct TreeNode *));
    int *ret = malloc(sizeof(int) * retArrSize);
    struct TreeNode *curr = root;
    int done = 0;
    while (!done)
    {
        while (curr)
        {
            if (stackTop + 2 >= stackSize)
            {
                stackSize *= 2;
                nodeStack =
                    realloc(nodeStack, sizeof(struct TreeNode *) * stackSize);
                nodeStack[++stackTop] = curr;
                nodeStack[++stackTop] = curr;
                curr = curr->left;
            }
            else
            {
                nodeStack[++stackTop] = curr;
                nodeStack[++stackTop] = curr;
                curr = curr->left;
            }
        }
        if (stackTop == -1)
            done = 1;
        curr = nodeStack[stackTop--];
        if (stackTop >= -1 && curr == nodeStack[stackTop])
        {
            curr = curr->right;
        }
        else
        {
            if ((retPtr + 1) >= retArrSize)
            {
                retArrSize++;
                ret = realloc(ret, sizeof(int) * retArrSize);
                ret[++retPtr] = curr->val;
                curr = NULL;
            }
            else
            {
                ret[++retPtr] = curr->val;
                curr = NULL;
            }
        }
    }
    *returnSize = retArrSize;
    return ret;
}
