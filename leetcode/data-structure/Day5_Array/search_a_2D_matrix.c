
typedef enum
{
    false,
    true
} bool;

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int m = matrixSize, n = *matrixColSize;
    // find starting row
    int left = 0, right = m * n - 1;
    int row, col;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        row = mid / n;
        col = mid % n;
        if (matrix[row][col] == target)
            return true;
        if (matrix[row][col] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}
