#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

enum
{
    LEFT,
    RIGHT
} leftorright;

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }
    /* Create two stack to store nodes of current levels and next levels. Pop
     * nodes from current level stack and push the child nodes to next level
     * stack. When the current level stack is empty, swap two stack.
     */
    struct TreeNode *stack_1[200];
    struct TreeNode *stack_2[200];
    struct TreeNode **currStack = stack_1; // aliasing for future swapping
    struct TreeNode **nextStack = stack_2; // aliasing for future swapping
    int stackTop_1 = 0;
    int stackTop_2 = 0;
    int currTop = stackTop_1; // aliasing, for swapping two stacks
    int nextTop = stackTop_2; // aliasing, for swapping two stacks
    int res[2000];            // Store results in zigzag order
    int resId = 0;
    int currSize = 0; // Record of current level size
    // Initiate valuable for leetcode
    *returnSize = 0;
    *returnColumnSizes = NULL;

    // Initiate left or right
    int left_or_right = LEFT;
    // push root to current stack to begin BFS
    currStack[currTop++] = root;
    while (currTop > 0)
    {
        // Top the current stack
        struct TreeNode *tmp = currStack[currTop - 1];
        if (tmp) // Exists
        {
            res[resId++] = tmp->val; // Store the value into temp array
            // Push nodes to next level stack
            if (left_or_right == LEFT) // Left or right
            {
                if (tmp->left)
                    nextStack[nextTop++] = tmp->left;
                if (tmp->right)
                    nextStack[nextTop++] = tmp->right;
            }
            else
            {
                if (tmp->right)
                    nextStack[nextTop++] = tmp->right;
                if (tmp->left)
                    nextStack[nextTop++] = tmp->left;
            }
            currTop--;  // Pop out the top
            currSize++; // Increment current level size
        }
        // All current level nodes have been visited
        if (currTop == 0)
        {
            left_or_right = (left_or_right == LEFT)
                                ? RIGHT
                                : LEFT; // Switch left right flag
            // Swap stack pointers
            struct TreeNode **tmpStack = currStack;
            currStack = nextStack;
            nextStack = tmpStack;
            // Swap stack counters
            int tmpTop = currTop;
            currTop = nextTop;
            nextTop = tmpTop;
            // Update returnSize and returnColumnSizes
            (*returnSize)++;
            *returnColumnSizes =
                realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
            (*returnColumnSizes)[*returnSize - 1] = currSize;
            // Reset current level size
            currSize = 0;
        }
    }
    // Collect result according to the returnSize and returnColumnSizes
    int **ret = malloc(sizeof(int *) * (*returnSize));
    int k = 0; // Iterate through the temp array
    for (int i = 0; i < *returnSize; i++)
    {
        ret[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
        for (int j = 0; j < (*returnColumnSizes)[i]; j++)
        {
            ret[i][j] = res[k];
            k++;
        }
    }
    return ret;
}
