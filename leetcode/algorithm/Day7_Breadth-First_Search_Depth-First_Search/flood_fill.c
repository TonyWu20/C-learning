#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

void paint(int **image, int rowSize, int colSize, int sr, int sc, int newColor,
           int curColor)
{
    if (sr < 0 || sr >= rowSize)
        return;
    if (sc < 0 || sc >= colSize)
        return;
    if (image[sr][sc] == curColor)
    {
        image[sr][sc] = newColor;
        paint(image, rowSize, colSize, sr - 1, sc, newColor, curColor);
        paint(image, rowSize, colSize, sr + 1, sc, newColor, curColor);
        paint(image, rowSize, colSize, sr, sc - 1, newColor, curColor);
        paint(image, rowSize, colSize, sr, sc + 1, newColor, curColor);
    }
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc,
                int newColor, int *returnSize, int **returnColumnSizes)
{
    int rowSize = imageSize;
    int colSize = *imageColSize;
    /* malloc returned array */
    *returnColumnSizes = malloc(rowSize * sizeof(int));
    *returnSize = rowSize;
    /* malloc each row */
    for (int i = 0; i < rowSize; i++)
    {
        (*returnColumnSizes)[i] = colSize;
    }
    int curColor = image[sr][sc];
    if (curColor != newColor)
        paint(image, rowSize, colSize, sr, sc, newColor, curColor);
    return image;
}
