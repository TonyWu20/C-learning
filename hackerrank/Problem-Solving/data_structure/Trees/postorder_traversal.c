#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
    {
        struct node *cur;

        if (data <= root->data)
        {
            cur = insert(root->left, data);
            root->left = cur;
        }
        else
        {
            cur = insert(root->right, data);
            root->right = cur;
        }

        return root;
    }
}

/* you only have to complete the function given below.
node is defined as

struct node {

    int data;
    struct node *left;
    struct node *right;

};

*/
void pushNode(struct node ***stack, struct node *np, int *stackTop)
{
    *stack = realloc(*stack, sizeof(struct node *) * (*stackTop + 3));
    (*stackTop) += 2;
    (*stack)[*stackTop - 1] = np;
    (*stack)[*stackTop] = np;
}
void postOrder(struct node *root)
{
    struct node **stack = NULL;
    int stackTop = -1;
    int *result = NULL;
    int resultLen = 0;
    struct node *np = root;
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
            result[resultLen - 1] = np->data;
            np = NULL;
        }
    }
    for (int i = 0; i < resultLen; ++i)
    {
        printf("%d%c", result[i], (i == resultLen - 1) ? '\n' : ' ');
    }
    free(stack);
    free(result);
}
