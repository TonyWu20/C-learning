#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array aand *columnSizes array must be malloced, assume
 * caller calls free().
 */

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c,
                    int *returnSize, int **returnColumnSizes)
{
    int m = matSize;
    int n = *matColSize;
    if (m * n - r * c)
    {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    // initialized each row to be a pointer to array (pointer) of int
    int **res = malloc(r * sizeof(int *));
    *returnColumnSizes = malloc(sizeof(int) * r);
    // initialized each row pointer to have columnSize c;
    for (int i = 0; i < r; ++i)
    {
        res[i] = calloc(c, sizeof(int));
        (*returnColumnSizes)[i] = c;
    }
    // flatten original matrix
    for (int i = 0; i < m * n; ++i)
    {
        res[i / c][i % c] = mat[i / c][i % c];
        // 4x5:
        // 0,1,2,3,4: [i/5] = 0; [i%5]=0,1,2,3,4;
        // 5,6,7,8,9: [i/5] = 1; [i%5]=0,1,2,3,4;
    }
    *returnSize = r;
    return res;
}
