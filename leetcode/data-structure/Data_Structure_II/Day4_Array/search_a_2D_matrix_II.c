// Tags: Array, Binary Search

typedef enum
{
    false,
    true
} bool;

bool s(int **matrix, int rowSize, int colSize, int r, int c, int target)
{
    if (r < 0 || r >= rowSize || c < 0 || c >= colSize)
        return false;
    int x = matrix[r][c];
    if (x == target)
        return true;
    if (x < target)
        return s(matrix, rowSize, colSize, r + 1, c, target);
    else
        return s(matrix, rowSize, colSize, r, c - 1, target);
}
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int r = 0;
    int c = *matrixColSize - 1;
    return s(matrix, matrixSize, *matrixColSize, r, c, target);
}
