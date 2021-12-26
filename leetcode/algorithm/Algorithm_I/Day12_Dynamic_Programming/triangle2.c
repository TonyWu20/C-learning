#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    for (int i = 1; i < triangleSize; ++i)
    {
        for (int j = 0; j < triangleColSize[i]; ++j)
        {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == triangleColSize[i] - 1)
                triangle[i][j] += triangle[i - 1][j - 1];
            else
            {
                int min = (triangle[i - 1][j] < triangle[i - 1][j - 1])
                              ? triangle[i - 1][j]
                              : triangle[i - 1][j - 1];
                triangle[i][j] += min;
            }
        }
    }
    int minTotal = INT_MAX;
    for (int j = 0; j < triangleColSize[triangleSize - 1]; ++j)
    {
        minTotal = (minTotal < triangle[triangleSize - 1][j])
                       ? minTotal
                       : triangle[triangleSize - 1][j];
    }
    return minTotal;
}

int main(int argc, char *argv[])
{
    int triangleSize = 4;
    int triangleColSize[] = {1, 2, 3, 4};
    int *triangle[] = {(int[]){2}, (int[]){3, 4}, (int[]){6, 5, 7},
                       (int[]){4, 1, 8, 3}};
    printf("%d\n", minimumTotal(triangle, triangleSize, triangleColSize));
    return 0;
}
