#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *div_n_con(int *nums, int start, int end);
struct TreeNode *newNode(int val);

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *root = div_n_con(nums, 0, numsSize - 1);
    return root;
}

struct TreeNode *div_n_con(int *nums, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left = div_n_con(nums, start, mid - 1);
    root->right = div_n_con(nums, mid + 1, end);
    return root;
}

struct TreeNode *newNode(int val)
{
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}
