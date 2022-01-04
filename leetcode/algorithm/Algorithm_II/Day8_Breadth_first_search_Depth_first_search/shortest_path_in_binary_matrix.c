#include <stdio.h>
#include <stdlib.h>

int shortestPathBinaryMatrix(int **grid, int gridSize, int *gridColSize)
{
    if (grid[0][0] || grid[gridSize - 1][*gridColSize - 1])
        return -1;
    int *qI = malloc(sizeof(int) * gridSize * (*gridColSize));
    int *qJ = malloc(sizeof(int) * gridSize * (*gridColSize));
    qI[0] = qJ[0] = 0;
    int front = 0, rear = 0, count = 0;
    int rearOld;
    grid[0][0] = 1;
    while (front <= rear)
    {
        count++;
        rearOld = rear;
        while (front <= rearOld)
        {
            int i = qI[front];
            int j = qJ[front];

            if (i == gridSize - 1 && j == gridSize - 1)
                return count;
            front++;
            for (int x = -1; x <= 1; ++x)
            {
                for (int y = -1; y <= 1; ++y)
                {
                    if (!(x == 0 && y == 0) && i + x < gridSize && i + x >= 0 &&
                        j + y < gridSize && j + y >= 0 &&
                        grid[x + i][y + j] == 0)
                    {
                        grid[x + i][y + j] = 1;
                        qI[++rear] = x + i;
                        qJ[rear] = y + j;
                    }
                }
            }
        }
    }
    return -1;
}
