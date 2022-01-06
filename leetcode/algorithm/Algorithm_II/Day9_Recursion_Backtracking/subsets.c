#include <stdlib.h>

void backTracking(int *nums, int numsSize, int start, int *arr, int len,
                  int **ret, int *rcs, int *idx)
{
    int i;
    if (start >= numsSize)
    {
        rcs[*idx] = len;
        ret[*idx] = realloc(ret[*idx], sizeof(int) * len);
        for (int i = 0; i < len; ++i)
        {
            ret[*idx][i] = arr[i];
        }
        (*idx)++;
        return;
    }
    for (i = start; i <= numsSize; i++)
    {
        if (i == numsSize)
        {
            backTracking(nums, numsSize, i + 1, arr, len, ret, rcs, idx);
        }
        else
        {
            arr[len] = nums[i];
            backTracking(nums, numsSize, i + 1, arr, len + 1, ret, rcs, idx);
        }
    }
}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 1 << numsSize;
    int *rcs = malloc(sizeof(int) * (*returnSize));
    int **ret = calloc(*returnSize, sizeof(int *));
    int idx = 0;
    int arr[10];
    backTracking(nums, numsSize, 0, arr, 0, ret, rcs, &idx);
    *returnColumnSizes = rcs;
    return ret;
}
