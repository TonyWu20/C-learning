#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder_traverse(struct TreeNode *root, int *arr, int *arrId, int k)
{
    if (root && *arrId < k)
    {
        inorder_traverse(root->left, arr, arrId, k);
        arr[(*arrId)++] = root->val;
        inorder_traverse(root->right, arr, arrId, k);
    }
}

int kthSmallest(struct TreeNode *root, int k)
{
    int arr[10000];
    int arrId = 0;
    inorder_traverse(root, arr, &arrId, k);
    return arr[k - 1];
}
