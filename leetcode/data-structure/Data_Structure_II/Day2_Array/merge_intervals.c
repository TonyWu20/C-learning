#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    // If the left numbers are the same, compare right numbers
    if (((int **)a)[0][0] == ((int **)b)[0][0])
        return (((int **)a)[0][1] - ((int **)b)[0][1]);
    // Sort intervals by comparing the left numbers
    return (((int **)a)[0][0] - ((int **)b)[0][0]);
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes)
{
    // Sort the intervals array
    qsort(intervals, intervalsSize, sizeof(int *), cmpfunc);
    // Create a stack for answer
    int **stack = malloc(sizeof(int *) * intervalsSize);
    int stackTop = -1;
    // Push first interval into the stack
    stack[++stackTop] = intervals[0];
    // Begin from second
    for (int i = 1; i < intervalsSize; ++i)
    {
        /* If the next interval left is larger than the top of the stack's
         * right, they are separated */
        if (intervals[i][0] > stack[stackTop][1])
        {
            // Push current interval to answer
            stack[++stackTop] = intervals[i];
        }
        /* The current interval left is inside the stack top's interval
         * Check if the current interval has larger right than stack top's
         * To see if they could be merged */
        else if (intervals[i][1] > stack[stackTop][1])
            stack[stackTop][1] = intervals[i][1];
    }
    // Cut space
    stack = realloc(stack, sizeof(int *) * (stackTop + 1));
    // Leetcode's trivials
    *returnSize = stackTop + 1;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = 2;
    }
    // Answer
    return stack;
}
