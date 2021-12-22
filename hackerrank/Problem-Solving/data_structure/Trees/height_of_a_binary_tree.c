#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
    {
        struct node *cur;

        if (data <= root->data)
        {
            cur = insert(root->left, data);
            root->left = cur;
        }
        else
        {
            cur = insert(root->right, data);
            root->right = cur;
        }

        return root;
    }
}

/* you only have to complete the function given below.
node is defined as

struct node {

    int data;
    struct node *left;
    struct node *right;

};

*/
struct QNode
{
    struct node *np;
    struct QNode *next;
};
struct Queue
{
    struct QNode *front, *rear;
    int count;
};
struct QNode *newNode(struct node *np)
{
    struct QNode *temp = malloc(sizeof(struct QNode));
    temp->np = np;
    temp->next = NULL;
    return temp;
}
struct Queue *createQueue()
{
    struct Queue *q = malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}
void enQueue(struct Queue *q, struct node *np)
{
    struct QNode *temp = newNode(np);
    if (!q->rear)
    {
        q->rear = q->front = temp;
        q->count++;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    q->count++;
}
void deQueue(struct Queue *q)
{
    if (!q->rear)
        return;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;
    free(temp);
    q->count--;
}
int getHeight(struct node *root)
{
    int height = -1;
    struct Queue *nodeQueue = createQueue();
    int nodeCount = 0;
    if (!root)
        return height;
    enQueue(nodeQueue, root);
    while (nodeQueue->count != 0)
    {
        height++;
        nodeCount = nodeQueue->count; // Count of current level
        while (nodeCount--)
        {
            struct node *curr = nodeQueue->front->np;
            if (curr->left)
            {
                enQueue(nodeQueue, curr->left);
            }
            if (curr->right)
            {
                enQueue(nodeQueue, curr->right);
            }
            deQueue(nodeQueue);
        }
    }
    return height;
}
