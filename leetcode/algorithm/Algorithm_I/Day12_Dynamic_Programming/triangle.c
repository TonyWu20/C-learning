#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    if (triangleSize == 1)
        return triangle[0][0];
    if (triangleSize == 2)
    {
        int minR2 =
            (triangle[1][0] > triangle[1][1]) ? triangle[1][1] : triangle[1][0];
        return triangle[0][0] + minR2;
    }
    int **dp = calloc(triangleSize, sizeof(int *));
    for (int i = 0; i < triangleSize; ++i)
    {
        dp[i] = calloc(triangleColSize[i], sizeof(int));
    }
    dp[0][0] = triangle[0][0];
    dp[1][0] = dp[0][0] + triangle[1][0];
    dp[1][1] = dp[0][0] + triangle[1][1];
    int minVal = INT_MAX;
    for (int i = 2; i < triangleSize; ++i)
    {
        int prevMin;
        for (int j = 0; j < triangleColSize[i]; ++j)
        {
            if (j == 0)
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (j == triangleColSize[i] - 1)
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else
            {
                prevMin = (dp[i - 1][j] < dp[i - 1][j - 1]) ? dp[i - 1][j]
                                                            : dp[i - 1][j - 1];
                dp[i][j] = triangle[i][j] + prevMin;
            }
        }
    }
    for (int i = 0; i < triangleSize; ++i)
    {
        for (int j = 0; j < triangleColSize[i]; ++j)
        {
            printf("%d%c", dp[i][j],
                   (j == triangleColSize[i] - 1) ? '\n' : ' ');
        }
    }
    for (int j = 0; j < triangleColSize[triangleSize - 1]; ++j)
    {
        minVal = (minVal < dp[triangleSize - 1][j]) ? minVal
                                                    : dp[triangleSize - 1][j];
    }
    return minVal;
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
