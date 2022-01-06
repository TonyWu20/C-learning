#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpFunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void subSets(int *nums, int numsSize, int start, int currLen, int subsetLen,
             int *arr, int **ret, int *rcs, int *idx)
{
    if (currLen == subsetLen)
    {
        rcs[*idx] = subsetLen;
        ret[*idx] = realloc(ret[*idx], sizeof(int) * subsetLen);
        memcpy(ret[*idx], arr, sizeof(int) * subsetLen);
        (*idx)++;
        return;
    }
    for (int i = start; i < numsSize; ++i)
    {
        if (i != start && nums[i] == nums[i - 1]) // duplicate
            continue;
        arr[currLen] = nums[i];
        subSets(nums, numsSize, i + 1, currLen + 1, subsetLen, arr, ret, rcs,
                idx);
    }
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes)
{
    *returnSize = 1 << numsSize;
    int *arr = malloc(sizeof(int) * numsSize);
    int **ret = calloc(*returnSize, sizeof(int *));

    int idx = 0;
    int *rcs = malloc(sizeof(int) * (*returnSize));
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    for (int i = 0; i <= numsSize; ++i)
    {
        subSets(nums, numsSize, 0, 0, i, arr, ret, rcs, &idx);
    }
    *returnSize = idx + 1;
    return ret;
}
