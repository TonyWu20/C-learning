#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct
{
    struct TreeNode **stack;
    int sp;
} BSTIterator;

int depth(struct TreeNode *root)
{
    int l, r;
    if (!root)
        return 0;
    l = depth(root->left) + 1;
    r = depth(root->right) + 1;
    return (l > r) ? l : r;
}

void push_left(BSTIterator *obj, struct TreeNode *np)
{
    while (np)
    {
        obj->stack[(obj->sp)++] = np;
        np = np->left;
    }
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
    BSTIterator *obj = calloc(1, sizeof(BSTIterator));
    int d = depth(root);
    if (d)
    {
        obj->stack = malloc(d * sizeof(struct TreeNode *));
        push_left(obj, root);
    }
    return obj;
}

bool bSTIteratorHasNext(BSTIterator *obj)
{
    return (obj->sp) ? true : false;
}

int bSTIteratorNext(BSTIterator *obj)
{
    struct TreeNode *np;

    np = obj->stack[--(obj->sp)];
    if (np->right)
        push_left(obj, np->right);
    return np->val;
}

void bSTIteratorFree(BSTIterator *obj)
{
    if (obj->stack)
        free(obj->stack);
    free(obj);
}
