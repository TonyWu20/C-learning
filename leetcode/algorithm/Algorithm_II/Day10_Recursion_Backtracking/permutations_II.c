#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void btPermute(int *nums, int numsSize, int start, int *used, int *tmp,
               int **result, int *rcs, int *idx)
{
    if (start == numsSize)
    {
        rcs[*idx] = numsSize;
        result[*idx] = malloc(sizeof(int) * numsSize);
        memcpy(result[*idx], tmp, sizeof(int) * numsSize);
        (*idx)++;
        return;
    }
    for (int i = 0; i < numsSize; ++i)
    {
        if (!used[i])
        {
            if (i != start && !used[i - 1] && nums[i] == nums[i - 1])
                continue;
            used[i] = 1;
            tmp[start] = nums[i];
            btPermute(nums, numsSize, start + 1, used, tmp, result, rcs, idx);
            used[i] = 0;
        }
    }
}

int **permuteUnique(int *nums, int numsSize, int *returnSize,
                    int **returnColumnSizes)
{
    *returnSize = factorial(numsSize); // 1<= numsSize <=8 no int overflow
    int *rcs = malloc(*returnSize * sizeof(int)); // short for returnColumnSizes
    int **result = calloc(*returnSize, sizeof(int *));
    int *used = calloc(numsSize, sizeof(int));
    int *tmp = malloc(numsSize * sizeof(int));
    int idx = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    btPermute(nums, numsSize, 0, used, tmp, result, rcs, &idx);
    *returnSize = idx;
    *returnColumnSizes = rcs;
    return result;
}
