#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    if (((int **)a)[0][0] == ((int **)b)[0][0])
        return (((int **)a)[0][1] - ((int **)b)[0][1]);
    return (((int **)a)[0][0] - ((int **)b)[0][0]);
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes)
{
    qsort(intervals, intervalsSize, sizeof(int *), cmpfunc);
    int **stack = malloc(sizeof(int *) * intervalsSize);
    int stackTop = -1;
    stack[++stackTop] = intervals[0];
    for (int i = 1; i < intervalsSize; ++i)
    {
        if (intervals[i][0] > stack[stackTop][1])
        {
            stack[++stackTop] = intervals[i];
        }
        else if (intervals[i][1] > stack[stackTop][1])
            stack[stackTop][1] = intervals[i][1];
    }
    stack = realloc(stack, sizeof(int *) * (stackTop + 1));
    *returnSize = stackTop + 1;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return stack;
}
