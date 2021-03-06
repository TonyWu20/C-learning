#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#define MAX_SIZE 6208

// The constraints given state that all elements of graph[i] are unique and no
// self-loop So the check visited can be skipped
void dfs(int **graph, int i, int **curr, int *currSize, int **answer,
         int graphSize, int *graphColSize, int *returnSize,
         int **returnColumnSizes)
{
    (*currSize)++;
    (*curr)[(*currSize) - 1] = i;
    if (i == graphSize - 1) // Reach target, here is graphSize-1;
    {
        // Store answer
        (*returnSize)++;
        answer[*returnSize - 1] = malloc(sizeof(int) * (*currSize));
        for (int i = 0; i < *currSize; ++i)
        {
            answer[*returnSize - 1][i] = (*curr)[i];
        }
        // Store answer size
        (*returnColumnSizes)[*returnSize - 1] = *currSize;
    }
    else
    {
        for (int j = 0; j < graphColSize[i]; ++j)
        {
            dfs(graph, graph[i][j], curr, currSize, answer, graphSize,
                graphColSize, returnSize, returnColumnSizes);
        }
    }
    (*currSize)--; // Back to previous node for next call
}
int **allPathsSourceTarget(int **graph, int graphSize, int *graphColSize,
                           int *returnSize, int **returnColumnSizes)
{
    int **answer =
        malloc(MAX_SIZE * sizeof(int *)); // Initialize the 'answer' array
                                          // assuming having the maximum size.
    *returnColumnSizes = malloc(
        MAX_SIZE * sizeof(int)); // Assuming the answer having maximum size
    int *curr = calloc(graphSize, sizeof(int));
    int currSize = 0; // For temporary tracking of answer
    *returnSize = 0;
    dfs(graph, 0, &curr, &currSize, answer, graphSize, graphColSize, returnSize,
        returnColumnSizes); // Begin the DFS search;
    // returnSize is updated after the DFS finished
    // Trimming arrays to exact size
    answer =
        realloc(answer, sizeof(int *) * (*returnSize)); // Trim to exact size;
    *returnColumnSizes = realloc(
        *returnColumnSizes, sizeof(int) * (*returnSize)); // Trim to exact size;
    free(curr);
    return answer;
}
