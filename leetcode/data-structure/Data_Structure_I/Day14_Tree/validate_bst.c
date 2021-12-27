#include <limits.h>
#include <stdio.h>

typedef enum
{
    false,
    true
} bool;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxBST(struct TreeNode *root)
{
    int max = INT_MIN;
    if (!root)
        return max;
    int left = maxBST(root->left);
    max = root->val;
    int right = maxBST(root->right);
    max = (max > left) ? max : left;
    max = (max > right) ? max : right;
    return max;
}

int minBST(struct TreeNode *root)
{
    int min = INT_MAX;
    if (!root)
        return min;
    int left = minBST(root->left);
    min = root->val;
    int right = minBST(root->right);
    min = (min < left) ? min : left;
    min = (min < right) ? min : right;
    return min;
}

bool isValidBST(struct TreeNode *root)
{
    if (root)
    {
        if (root->left && root->val <= maxBST(root->left))
            return false;
        if (root->right && root->val >= minBST(root->right))
            return false;
        if (!isValidBST(root->left) || !isValidBST(root->right))
            return false;
    }
    return true;
}
