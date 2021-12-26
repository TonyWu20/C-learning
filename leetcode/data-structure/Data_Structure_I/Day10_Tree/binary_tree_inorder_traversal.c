#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *inorderTraversal(struct TreeNode *root, int *returnSize)
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
        // Push current node to stack and traverse to left
        while (curr)
        {
            if ((stackTop + 1) >= stackSize)
            {
                stackSize *= 2;
                nodeStack =
                    realloc(nodeStack, sizeof(struct TreeNode *) * stackSize);
                nodeStack[++stackTop] = curr;
                curr = curr->left;
            }
            else
            {
                nodeStack[++stackTop] = curr;
                curr = curr->left;
            }
        }
        // curr == NULL
        if (stackTop > -1) /* Not empty */
        {
            if ((retPtr + 1) >= retArrSize)
            {
                retArrSize *= 2;
                ret = realloc(ret, sizeof(int) * retArrSize);
                ret[++retPtr] = nodeStack[stackTop]->val;
                curr = nodeStack[stackTop--]->right;
            }
            else
            {
                ret[++retPtr] = nodeStack[stackTop]->val;
                curr = nodeStack[stackTop--]->right;
            }
        }
        else
        {
            done = 1;
        }
    }
    retArrSize = retPtr + 1;
    ret = realloc(ret, sizeof(int) * retArrSize);
    *returnSize = retArrSize;
    return ret;
}
