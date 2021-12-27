#include <stdio.h>
#include <stdlib.h>
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

void preOrder(struct TreeNode *root, int *arr, int *count)
{
    if (!root)
        return;
    preOrder(root->left, arr, count);
    arr[(*count)++] = root->val;
    preOrder(root->right, arr, count);
}

int get_element(struct TreeNode *root)
{
    if (!root)
        return 0;
    return get_element(root->left) + get_element(root->right) + 1;
}
bool findTarget(struct TreeNode *root, int k)
{
    int count = get_element(root);
    int *arr = malloc(sizeof(int) * count);
    count = 0;
    preOrder(root, arr, &count);
    int l = 0, r = count - 1;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum == k)
        {
            free(arr);
            return true;
        }
        if (sum > k)
            r--;
        else
            l++;
    }
    free(arr);
    return false;
}
