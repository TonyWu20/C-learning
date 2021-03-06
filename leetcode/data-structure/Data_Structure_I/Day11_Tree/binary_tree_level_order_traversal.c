#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define SIZE 2000UL
struct TreeNode *queue[SIZE];
int front = -1;
int rear = -1;

void enque(struct TreeNode *nd)
{
    if (rear == SIZE - 1)
    {
        printf("queue full\n");
    }

    queue[++rear] = nd;
    if (front == -1)
    {
        front = 0;
    }
}

struct TreeNode *deque()
{
    if (front == -1)
    {
        return NULL;
    }

    struct TreeNode *tmp = queue[front];
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    return tmp;
}

int **__level_order(struct TreeNode *root, int *returnSize,
                    int **returnColumnSizes)
{
    int cur_lvl;
    int next_lvl;
    int nums_per_lvl[2000] = {1};
    int cur_lvl_cnt = 0;

    int **ret = malloc(sizeof(int *) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);

    cur_lvl = 0;
    next_lvl = 1;
    ret[0] = malloc(sizeof(int));
    (*returnColumnSizes)[0] = 1;

    struct TreeNode *nd = root;
    while (nd)
    {
        if (cur_lvl_cnt >= nums_per_lvl[cur_lvl])
        {
            cur_lvl++;
            next_lvl++;
            cur_lvl_cnt = 0;
            ret[cur_lvl] = malloc(sizeof(int) * nums_per_lvl[cur_lvl]);
            (*returnColumnSizes)[cur_lvl] = nums_per_lvl[cur_lvl];
        }

        if (nd->left)
        {
            enque(nd->left);
            nums_per_lvl[next_lvl]++;
        }
        if (nd->right)
        {
            enque(nd->right);
            nums_per_lvl[next_lvl]++;
        }

        ret[cur_lvl][cur_lvl_cnt++] = nd->val;
        nd = deque();
    }

    *returnSize = cur_lvl + 1;
    return ret;
}

int **levelOrder(struct TreeNode *root, int *returnSize,
                 int **returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    return __level_order(root, returnSize, returnColumnSizes);
}
