#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSmallestSetOfVertices(int n, int **edges, int edgesSize,
                               int *edgesColSize, int *returnSize)
{
    int in[n];
    for (int i = 0; i < n; ++i)
    {
        in[i] = 0;
    }
    for (int i = 0; i < edgesSize; ++i)
    {
        in[edges[i][1]]++;
    }
    int count = 0;
    int *ret = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        if (in[i] == 0) // Find source in DAG
            ret[count++] = i;
    }
    *returnSize = count;
    return ret;
}
