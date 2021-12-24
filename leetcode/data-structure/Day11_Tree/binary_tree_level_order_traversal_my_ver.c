#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QNode
{
    struct TreeNode *np;
    struct QNode *next;
};
typedef struct
{
    struct QNode *front;
    struct QNode *rear;
    int size;
} Queue;

struct QNode *newQNode(struct TreeNode *np)
{
    struct QNode *qp = malloc(sizeof(struct QNode));
    qp->np = np;
    qp->next = NULL;
    return qp;
}

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enQueue(Queue *qp, struct TreeNode *np)
{
    struct QNode *newQN = newQNode(np);
    if (!qp->rear)
    {
        qp->front = qp->rear = newQN;
        qp->size++;
        return;
    }
    qp->rear->next = newQN;
    qp->rear = newQN;
    qp->size++;
}
void deQueue(Queue *qp)
{
    if (!qp->rear)
        return;
    struct QNode *popped = qp->front;
    qp->front = qp->front->next;
    if (!qp->front)
        qp->rear = NULL;
    free(popped);
    qp->size--;
}

int **storeLevel(struct TreeNode *root, int *returnSize,
                 int **returnColumnSizes)
{
    int **res = malloc(sizeof(int *) * 2000);
    *returnSize = 0;
    Queue *queue = createQueue();
    if (!root)
    {
        return NULL;
    }
    enQueue(queue, root);
    while (queue->size != 0)
    {
        int nodeCount = queue->size;
        (*returnSize)++;
        res[*returnSize - 1] = malloc(sizeof(int) * nodeCount);
        (*returnColumnSizes)[*returnSize - 1] = nodeCount;
        for (int i = 0; i < nodeCount; ++i)
        {
            struct TreeNode *curr = queue->front->np;
            res[*returnSize - 1][i] = curr->val;
            if (curr->left)
                enQueue(queue, curr->left);
            if (curr->right)
                enQueue(queue, curr->right);
            deQueue(queue);
        }
    }
    free(queue);
    return res;
}
int **levelOrder(struct TreeNode *root, int *returnSize,
                 int **returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    int **res = storeLevel(root, returnSize, returnColumnSizes);
    res = realloc(res, sizeof(int *) * (*returnSize));
    *returnColumnSizes =
        realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
    return res;
}
