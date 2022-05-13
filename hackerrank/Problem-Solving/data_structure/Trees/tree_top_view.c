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

/* Queue */
struct QNode
{
    struct node *np;
    int distance; // To record the distance from the root
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
    int count;
};
struct QNode *newNode(struct node *np, int dist)
{
    struct QNode *temp = malloc(sizeof(struct QNode));
    temp->np = np;
    temp->distance = dist;
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
void enQueue(struct Queue *q, struct node *np, int dist)
{
    struct QNode *temp = newNode(np, dist);
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
void topView(struct node *root)
{
    struct Queue *q = createQueue();
    int hd = 0;
    int l = 0;
    int r = 0;
    int leftStack[100];
    int leftStackTop = -1;
    int rightVec[100];
    int rightCount = -1;
    struct node *np;
    enQueue(q, root, 0); // Push root node, set distance to 0 to start
    while (q->count)     // while Queue q is not empty
    {
        np = q->front->np;       // current tree node
        hd = q->front->distance; // current distance
        if (hd < l)              // hd < l, this node is the leftmost node now.
        {
            leftStack[++leftStackTop] = np->data; // push data to stack
            l = hd;                               // update leftmost distance
        }
        else if (hd > r) // hd > r, this node is the rightmost node now
        {
            rightVec[++rightCount] = np->data; // add data to the array
            r = hd;                            // update rightmost distance
        }
        if (np->left) // if this node has left child
        {
            enQueue(q, np->left,
                    hd - 1); // add left child to queue, set distance as hd - 1
        }
        if (np->right)
        {
            enQueue(q, np->right,
                    hd + 1); // add right child to queue, set distance as hd + 1
        }
        deQueue(q); // pop the current node from the queue
    }
    while (leftStackTop >=
           0) // Print data in the stack in reverse order for the leftmost part
    {
        printf("%d ", leftStack[leftStackTop--]); // pop stack
    }
    printf("%d ", root->data); // print root
    for (int i = 0; i <= rightCount;
         ++i) // print data in the array for the rightmost part
    {
        printf("%d ", rightVec[i]);
    }
}
