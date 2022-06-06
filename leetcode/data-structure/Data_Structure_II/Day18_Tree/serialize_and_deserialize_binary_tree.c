#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/** Encodes a tree to a single string. */
char *serialize(struct TreeNode *root)
{
    static struct TreeNode *queue[20480];
    int front = 0, rear = 0;
    static char result_str[1024 * 1024];
    char *s = result_str;
    queue[rear++] = root;
    while (front < rear)
    {
        struct TreeNode *node = queue[front++]; // DeQueue
        if (node)
        {
            int size = snprintf(NULL, 0, "%d ", node->val);
            s += snprintf(s, size + 1, "%d ", node->val);
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
        else
        {
            s += sprintf(s, "n ");
        }
    }
    s[-1] = '\0';
    return result_str;
}
struct TreeNode *newNode(int val)
{
    struct TreeNode *new_node = malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode *deserialize(char *data)
{
    static struct TreeNode *queue[20480];
    struct TreeNode *root = NULL;
    int front = 0, rear = 0;
    char *p = strtok(data, " ");
    if (p && *p != 'n')
    {
        root = newNode(atoi(p));
        queue[rear++] = root;
    }
    while (front < rear)
    {
        struct TreeNode *node = queue[front++];
        if (node)
        {
            char *left = strtok(NULL, " ");
            if (left && *left != 'n')
            {
                node->left = newNode(atoi(left));
                queue[rear++] = node->left;
            }
        }
        char *right = strtok(NULL, " ");
        if (right && *right != 'n')
        {
            node->right = newNode(atoi(right));
            queue[rear++] = node->right;
        }
    }
    return root;
}
