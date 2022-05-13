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
/* prototypes */
struct node **createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);
#define MAX_Q_SIZE 500

void levelOrder(struct node *root)
{
    int rear, front;
    front = rear = 0;
    struct node **queue = createQueue(&front, &rear);
    struct node *np = root;
    while (np)
    {
        printf("%d ", np->data);
        /* Enqueue left child */
        if (np->left)
        {
            enQueue(queue, &rear, np->left);
        }
        /* Enqueue right child */
        if (np->right)
        {
            enQueue(queue, &rear, np->right);
        }
        /* Dequeue node and make it temp node np */
        np = deQueue(queue, &front);
    }
    free(queue);
}
/* UTILITY FUNCTIONS */
struct node **createQueue(int *front, int *rear)
{
    struct node **queue = malloc(sizeof(struct node *) * MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

int main()
{
    struct node *root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    levelOrder(root);
    return 0;
}
