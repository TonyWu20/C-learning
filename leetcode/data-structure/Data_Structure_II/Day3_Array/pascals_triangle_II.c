#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fast but high memory usage
// Extra Space O(rowIndex^2)
/*int *getRow(int rowIndex, int *returnSize)*/
/*{*/
/*int **triangle = calloc(rowIndex + 1, sizeof(int *));*/
/*triangle[0] = malloc(sizeof(int));*/
/*triangle[0][0] = 1;*/
/*for (int i = 1; i <= rowIndex; ++i)*/
/*{*/
/*for (int j = 0; j <= rowIndex; ++j)*/
/*{*/
/*if (j == 0 || j == rowIndex)*/
/*triangle[i][j] = 1;*/
/*else*/
/*triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];*/
/*}*/
/*}*/
/*int *ret = triangle[rowIndex];*/
/*free(triangle);*/
/**returnSize = rowIndex;*/
/*return ret;*/
/*}*/

int *getRow(int rowIndex, int *returnSize)
{
    int size = rowIndex + 1;
    *returnSize = size;
    int *res = malloc(sizeof(int) * size);
    res[0] = 1;
    if (size == 1)
        return res;

    int *prev = malloc(sizeof(int) * rowIndex);
    if (size > 1)
        prev[0] = 1;
    if (size > 2)
        prev[1] = 1;
    for (int i = 1; i < rowIndex; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            res[j] = prev[j - 1] + prev[j];
        }
        res[i + 1] = 1;
        memcpy(prev, res, sizeof(int) * rowIndex);
    }
    res[rowIndex] = 1;
    free(prev);
    return res;
}
