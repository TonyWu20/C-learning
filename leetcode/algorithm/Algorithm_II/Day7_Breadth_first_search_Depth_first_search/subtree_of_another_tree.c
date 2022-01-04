struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef enum
{
    false,
    true
} bool;

bool isEqual(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (!root && !subRoot)
        return true;
    else if (!root || !subRoot)
        return false;
    return (root->val == subRoot->val) && isEqual(root->left, subRoot->left) &&
           isEqual(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (!root)
        return false;
    if (isEqual(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
