#include <stdio.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void dfs(struct Node *root, struct Node *next)
{
    if (!root)
        return;
    root->next = next;
    struct Node *tmp = NULL;
    while (next)
    {
        if (next->left)
        {
            tmp = next->left;
            break;
        }
        else if (next->right)
        {
            tmp = next->right;
            break;
        }
        else
            next = next->next;
    }
    dfs(root->right, tmp);
    if (root->right)
        dfs(root->left, root->right);
    else
        dfs(root->left, tmp);
}

struct Node *connect(struct Node *root)
{
    dfs(root, NULL);
    return root;
}

struct Node *bfsConnect(struct Node *root)
{
    if (!root)
        return NULL;
    struct Node *first = root, *cur, *pre;
    while (first)
    {
        cur = first;
        pre = first = NULL;
        while (cur)
        {
            if (cur->left)
            {
                if (pre)
                    pre->next = cur->left;
                else
                    first = cur->left;
                pre = cur->left;
            }
            if (cur->right)
            {
                if (pre)
                    pre->next = cur->right;
                else
                    first = cur->right;
                pre = cur->right;
            }
            cur = cur->next;
        }
    }
    return root;
}
