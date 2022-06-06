#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *minValueNode(struct TreeNode *root)
{
    struct TreeNode *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    if (root->left == NULL)
    {
        struct TreeNode *tmp = root->right;
        free(root);
        return tmp;
    }
    if (root->right == NULL)
    {
        struct TreeNode *tmp = root->left;
        free(root);
        return tmp;
    }
    struct TreeNode *succ = minValueNode(root->right);
    root->val = succ->val;
    root->right = deleteNode(root, succ->val);
    return root;
}
