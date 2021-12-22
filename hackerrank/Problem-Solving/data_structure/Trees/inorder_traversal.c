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
void pushNode(struct node ***stackAdr, struct node *pushed, int *stackTop)
{
    (*stackTop)++;
    *stackAdr = realloc(*stackAdr, sizeof(struct node *) * (*stackTop + 1));
    (*stackAdr)[*stackTop] = pushed;
}
void inOrder(struct node *root)
{
    struct node **stack = NULL;
    int stackTop = -1;
    int *result = NULL;
    int resultLen = 0;
    int done = 0;
    while (!done)
    {
        while (root)
        {
            pushNode(&stack, root, &stackTop);
            root = root->left;
        }
        root = stack[stackTop--];
        resultLen++;
        result = realloc(result, sizeof(int) * (resultLen + 1));
        result[resultLen - 1] = root->data;
        root = root->right;
        if (!root && stackTop == -1)
            done = 1;
    }
    for (int i = 0; i < resultLen; ++i)
        printf("%d%c", result[i], (resultLen - 1 == i) ? '\n' : ' ');
}

int main()
{
    struct node *root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    inOrder(root);
    return 0;
}
