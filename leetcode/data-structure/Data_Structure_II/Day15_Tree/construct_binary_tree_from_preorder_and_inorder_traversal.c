#include <stdlib.h>

/* Constraints:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define HASHSIZE 6001

int hash(int val)
{
    return (val + 3000) % HASHSIZE;
}

struct TreeNode *arrayToTree(int *preorder, int preorderSize,
                             int *preorderIndex, int inorder_left,
                             int inorder_right, int *hashTab);
struct TreeNode *newNode(int val);

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
                           int inorderSize)
{
    // Construct a hash table to store the index of value in inorder array
    int hashTab[6001];
    for (int i = 0; i < preorderSize; ++i)
    {
        hashTab[hash(inorder[i])] = i;
    }
    int preorderIndex = 0;
    struct TreeNode *root = arrayToTree(preorder, preorderSize, &preorderIndex,
                                        0, inorderSize - 1, hashTab);
    return root;
}

struct TreeNode *arrayToTree(int *preorder, int preorderSize,
                             int *preorderIndex, int inorder_left,
                             int inorder_right, int *hashTab)
{
    if (inorder_left > inorder_right || *preorderIndex >= preorderSize)
        return NULL;
    int root_value = preorder[(*preorderIndex)++];
    struct TreeNode *root = newNode(root_value);
    root->left =
        arrayToTree(preorder, preorderSize, preorderIndex, inorder_left,
                    hashTab[hash(root_value)] - 1, hashTab);
    root->right =
        arrayToTree(preorder, preorderSize, preorderIndex,
                    hashTab[hash(root_value)] + 1, inorder_right, hashTab);
    return root;
}

struct TreeNode *newNode(int val)
{
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}
