#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;

#define MAX_COMBO_NUM 150
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void searchSum(int *candidates, int candidatesSize, int target, int start,
               int currSum, int currSize, int *tmp, int *idx, int **ans,
               int **returnColumnSizes)
{
    if (currSum == target)
    {
        ans[*idx] = malloc(sizeof(int) * currSize);
        memcpy(ans[*idx], tmp, sizeof(int) * currSize);
        (*returnColumnSizes)[*idx] = currSize;
        (*idx)++;
        return;
    }
    int rmd = target - currSum;
    for (int i = start; i < candidatesSize; ++i)
    {
        if (candidates[i] > rmd)
            break;
        currSum += candidates[i];
        tmp[currSize] = candidates[i];
        // Passing current pos as start to the next recur call
        // Due to the loop start from 'start', no back repetition would be made
        // e.g. [2, 2, 3] and [3, 2, 2]
        // Required the array to be sortedi in ascending order first
        searchSum(candidates, candidatesSize, target, i, currSum, currSize + 1,
                  tmp, idx, ans, returnColumnSizes);
        currSum -= candidates[i];
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target,
                     int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int **ans = malloc(sizeof(int *) * MAX_COMBO_NUM);
    int *tmp = malloc(sizeof(int) * (target / candidates[0] + 1));
    int idx = 0;
    *returnColumnSizes = malloc(sizeof(int) * MAX_COMBO_NUM);
    searchSum(candidates, candidatesSize, target, 0, 0, 0, tmp, &idx, ans,
              returnColumnSizes);
    *returnSize = idx;
    return ans;
}
