#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

void dfs(int **isConnected, int i, int colSize, bool *visited)
{
    visited[i] = true;
    for (int j = 0; j < colSize; ++j)
    {
        if (isConnected[i][j] == 1 && !visited[j])
            dfs(isConnected, j, colSize, visited);
    }
}

int findCircleNum(int **isConnected, int isConnectedSize,
                  int *isConnectedColSize)
{
    bool *visited = calloc(isConnectedSize, sizeof(bool));
    int count = 0;
    for (int i = 0; i < isConnectedSize; ++i)
    {
        if (!visited[i])
        {
            count++;
            dfs(isConnected, i, *isConnectedColSize, visited);
        }
    }
    return count;
}
