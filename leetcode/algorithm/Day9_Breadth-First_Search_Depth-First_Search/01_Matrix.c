// Dynamic programming
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int min(int a, int b)
{
    return (a < b) ? a : b;
}
int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize,
                   int **returnColumnSizes)
{
    if (*matColSize == 0)
        return mat;
    int rowSize = matSize;
    int colSize = *matColSize;
    *returnSize = rowSize;
    int **dist = malloc(rowSize * sizeof(*dist));
    *returnColumnSizes = matColSize;

    for (int i = 0; i < rowSize; ++i)
    {
        dist[i] = malloc(colSize * sizeof(int));
        for (int j = 0; j < colSize; ++j)
        {
            if (!mat[i][j])
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX - 100000;
        }
    }
    // scan from top to bottom-left to right
    for (int i = 0; i < rowSize; ++i)
    {
        for (int j = 0; j < colSize; ++j)
        {
            if (mat[i][j])
            {
                // go back up or left, where is already visited
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }
    // scan from bottom to top-right to left
    for (int i = rowSize - 1; i >= 0; --i)
    {
        for (int j = colSize - 1; j >= 0; --j)
        {
            if (mat[i][j])
            {
                if (i < rowSize - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < colSize - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
    }
    return dist;
}
