#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RECUR 0

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

#if (RECUR)
void preOrder(struct node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
#else
void preOrder(struct node *root)
{
    struct node **stack = NULL;
    int resId = -1;
    int *res = NULL;
    int stackTop = -1;
    stack = realloc(stack, sizeof(struct node *) * (++stackTop + 1));
    stack[stackTop] = root;
    while (stackTop > -1)
    {
        struct node *np = stack[stackTop--];
        if (np)
        {
            res = realloc(res, sizeof(int) * (++resId + 1));
            res[resId] = np->data;
        }
        if (np->right)
        {
            stack = realloc(stack, sizeof(struct node *) * (++stackTop + 1));
            stack[stackTop] = np->right;
        }
        if (np->left)
        {
            stack = realloc(stack, sizeof(struct node *) * (++stackTop + 1));
            stack[stackTop] = np->left;
        }
    }
    for (int i = 0; i < resId + 1; ++i)
    {
        printf("%d%c", res[i], (i != resId) ? ' ' : '\n');
    }
    free(stack);
    free(res);
}
#endif
