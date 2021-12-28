#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int **mat, int matSize, int i, int j, int cur, char dir)
{
    if (i < 0 || j < 0 || i >= matSize || j >= matSize)
        return;
    if (mat[i][j])
        return;
    mat[i][j] = cur;
    if (dir == 'u')
    {
        fillMatrix(mat, matSize, i - 1, j, cur + 1, 'u');
    }
    fillMatrix(mat, matSize, i, j + 1, cur + 1, 'r');
    fillMatrix(mat, matSize, i + 1, j, cur + 1, 'd');
    fillMatrix(mat, matSize, i, j - 1, cur + 1, 'l');
    fillMatrix(mat, matSize, i - 1, j, cur + 1, 'u');
}

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    int **mat = calloc(n, sizeof(int *));
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        mat[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    fillMatrix(mat, n, 0, 0, 1, 'r');
    *returnSize = n;
    return mat;
}
