#include <stdio.h>
#include <stdlib.h>
#define ITER 0
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#if ITER

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

int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    int height = 0;
    Queue *queue = createQueue();
    enQueue(queue, root);
    while (queue->size)
    {
        height++;
        int nodeCount = queue->size;
        while (nodeCount--)
        {
            struct TreeNode *curr = queue->front->np;
            if (curr->left)
                enQueue(queue, curr->left);
            if (curr->right)
                enQueue(queue, curr->right);
            deQueue(queue);
        }
    }
    return height;
}
#else
int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    int leftD = maxDepth(root->left);
    int rightD = maxDepth(root->right);
    return (leftD > rightD) ? leftD + 1 : rightD + 1;
}
#endif
