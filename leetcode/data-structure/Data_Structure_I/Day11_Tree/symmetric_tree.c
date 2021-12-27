#include <stdio.h>
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
} Bool;
#if RECUR
Bool parallelCheck(struct TreeNode *l, struct TreeNode *r)
{
    if (!l && !r)
        return true;
    if (!l || !r)
        return false;
    if (l->val != r->val)
        return false;
    return parallelCheck(l->left, r->right) && parallelCheck(l->right, r->left);
}

Bool isSymmetric(struct TreeNode *root)
{
    if (!root)
        return true;
    return parallelCheck(root->left, root->right);
}
#else
struct TreeNode *queue[1000];
int front = -1;
int rear = -1;

void enQueue(struct TreeNode *np)
{
    if (rear == -1)
    {
        front = rear = 0;
        queue[rear] = np;
    }
    queue[++rear] = np;
}

struct TreeNode *deQueue()
{
    if (front == -1)
        return NULL;
    struct TreeNode *popped = queue[front];
    front++;
    if (front > rear)
        front = rear = -1;
    return popped;
}

Bool isSymmetric(struct TreeNode *root)
{
    if (!root)
        return true;
    enQueue(root);
    int nodeNum;
    struct TreeNode *curr;
    while ((nodeNum = rear - front + 1))
    {
        int j = rear;
        for (int i = 0; i < nodeNum; ++i)
        {
            curr = queue[front];
            if (curr)
            {
                enQueue(curr->left);
                enQueue(curr->right);
            }
            if (front < j)
            {
                if ((curr || queue[j]) != (curr && queue[j]))
                {
                    return false;
                }
                else if (curr && (curr->val != queue[j]->val))
                {
                    return false;
                }
            }
            front++;
            j--;
        }
    }
    return true;
}

#endif

int main()
{
    struct TreeNode root[1];
    root[0].left = NULL;
    root[0].right = NULL;
    root[0].val = 1;
    printf("%d\n", isSymmetric(root));
    return 0;
}
