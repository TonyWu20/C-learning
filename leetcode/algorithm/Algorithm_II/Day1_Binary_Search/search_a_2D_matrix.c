typedef enum
{
    false,
    true
} bool;

bool binSearch(int **matrix, int colSize, int start, int end, int target)
{
    if (start > end)
        return false;
    int mid = (start + end) / 2;
    int midVal = matrix[mid / colSize][mid % colSize];
    if (midVal == target)
        return true;
    if (midVal > target)
        return binSearch(matrix, colSize, start, mid - 1, target);
    return binSearch(matrix, colSize, mid + 1, end, target);
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int rowSize = matrixSize, colSize = *matrixColSize;
    return binSearch(matrix, colSize, 0, rowSize * colSize - 1, target);
}
