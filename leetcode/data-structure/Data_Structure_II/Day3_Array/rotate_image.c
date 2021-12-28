#if APPROACH1

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int l = matrixSize;
    int odd = (l % 2);
    int i_limit = (odd) ? matrixSize / 2 : matrixSize / 2 + 1;
    int j_limit = matrixSize - 1;
    int moved = matrixSize - 1;
    for (int i = 0; i < i_limit; ++i)
    {
        for (int j = i; j < (j_limit - i); ++j)
        {
            swap(&matrix[i][j], &matrix[j][moved - i]);
            swap(&matrix[i][j], &matrix[moved - i][moved - j]);
            swap(&matrix[i][j], &matrix[moved - j][i]);
        }
    }
}
#else
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void transpose(int **matrix, int matrixSize)
{
    for (int i = 0; i < matrixSize - 1; ++i)
    {
        for (int j = i + 1; j < matrixSize; ++j)
        {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}
void reverse(int **matrix, int matrixSize)
{
    for (int i = 0; i < matrixSize; ++i)
    {
        int start = 0, end = matrixSize - 1;
        while (start < end)
        {
            swap(&matrix[i][start++], &matrix[i][end--]);
        }
    }
}
void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    transpose(matrix, matrixSize);
    reverse(matrix, matrixSize);
}
#endif
