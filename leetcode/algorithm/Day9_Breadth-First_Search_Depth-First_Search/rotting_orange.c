#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    int r;
    int c;
} node;

bool isAllRotten(int **grid, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize * colSize; ++i)
    {
        if (grid[i / colSize][i % colSize] == 1)
            return false;
    }
    return true;
}

void rotAround(int **grid, int rowSize, int colSize, int r, int c, node *q,
               int *head)
{
    if (r > 0 && grid[r - 1][c] == 1)
    {
        (*head)++;
        q[*head].r = r - 1;
        q[*head].c = c;
        grid[r - 1][c] = 3;
    }
    if (r + 1 < rowSize && grid[r + 1][c] == 1)
    {
        (*head)++;
        q[*head].r = r + 1;
        q[*head].c = c;
        grid[r + 1][c] = 3;
    }
    if (c > 0 && grid[r][c - 1] == 1)
    {
        (*head)++;
        q[*head].r = r;
        q[*head].c = c - 1;
        grid[r][c - 1] = 3;
    }
    if (c + 1 < colSize && grid[r][c + 1] == 1)
    {
        (*head)++;
        q[*head].r = r;
        q[*head].c = c + 1;
        grid[r][c + 1] = 3;
    }
}

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{
    int rowSize = gridSize, colSize = *gridColSize;
    node *q = malloc(sizeof(node) * (rowSize * colSize));
    int head = -1;
    int tail = -1;
    int i, j;
    for (i = 0; i < rowSize; ++i)
    {
        for (j = 0; j < colSize; ++j)
        {
            if (grid[i][j] == 2)
                rotAround(grid, rowSize, colSize, i, j, q, &head);
        }
    }

    if (head == -1)
    {
        if (isAllRotten(grid, rowSize, colSize))
            return 0;
        else
            return -1;
    }

    int m = 0;
    while (tail < head)
    {
        ++m;
        int tmp_tail = tail;
        int tmp_head = head;
        while (++tmp_tail <= tmp_head)
        {
            rotAround(grid, rowSize, colSize, q[tmp_tail].r, q[tmp_tail].c, q,
                      &head);
        }
        tail = tmp_head;
    }

    if (isAllRotten(grid, rowSize, colSize))
        return m;
    return -1;
}
