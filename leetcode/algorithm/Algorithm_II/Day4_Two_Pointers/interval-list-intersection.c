#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int **intervalIntersection(int **firstList, int firstListSize,
                           int *firstListColSize, int **secondList,
                           int secondListSize, int *secondListColSize,
                           int *returnSize, int **returnColumnSizes)
{
    if (!firstListSize || !secondListSize)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int **ansStack = malloc(sizeof(int *) * (firstListSize + secondListSize)),
        stackTop = -1;
    int firstPtr = 0, secondPtr = 0;
    while (firstPtr < firstListSize || secondPtr < secondListSize)
    {
        int left = max(firstList[firstPtr][0], secondList[secondPtr][0]);
        int right = min(firstList[firstPtr][1], secondList[secondPtr][1]);
        if (left <= right)
        {
            ++stackTop;
            ansStack[stackTop] = malloc(sizeof(int) * 2);
            ansStack[stackTop][0] = left;
            ansStack[stackTop][1] = right;
        }
        if (firstList[firstPtr][1] < secondList[secondPtr][1])
            firstPtr++;
        else
            secondPtr++;
    }
    ansStack = realloc(ansStack, sizeof(int *) * (stackTop + 1));
    *returnSize = stackTop + 1;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i <= stackTop; ++i)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return ansStack;
}
