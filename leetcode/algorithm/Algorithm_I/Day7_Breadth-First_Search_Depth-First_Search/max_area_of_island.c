#include <stdio.h>

int walkIsland(int **grid, int gridSize, int *gridColSize, int r, int c,
               int checked[][*gridColSize])
{
    if (r < 0 || r >= gridSize || c < 0 || c >= *gridColSize ||
        grid[r][c] == 0 || checked[r][c])
    {
        return 0;
    }
    checked[r][c] = 1;
    return (1 + walkIsland(grid, gridSize, gridColSize, r + 1, c, checked) +
            walkIsland(grid, gridSize, gridColSize, r - 1, c, checked) +
            walkIsland(grid, gridSize, gridColSize, r, c + 1, checked) +
            walkIsland(grid, gridSize, gridColSize, r, c - 1, checked));
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
    int checked[gridSize][*gridColSize];
    int maxArea = 0;
    for (int i = 0; i < gridSize * (*gridColSize); i++)
    {
        checked[i / (*gridColSize)][i % (*gridColSize)] = 0;
    }
    for (int i = 0; i < gridSize * (*gridColSize); i++)
    {
        int area;
        area = walkIsland(grid, gridSize, gridColSize, i / (*gridColSize),
                          i % (*gridColSize), checked);
        maxArea = (area > maxArea) ? area : maxArea;
    }
    return maxArea;
}
