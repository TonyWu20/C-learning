#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void combination(int *nums, int numsSize, int target, int start, int len,
                 int *tmp, int **ans, int *idx, int **rcs)
{
    if (target == 0)
    {
        ans[*idx] = malloc(sizeof(int) * len);
        memcpy(ans[*idx], tmp, sizeof(int) * len);
        (*rcs)[*idx] = len;
        (*idx)++;
        return;
    }
    if (len == 30)
        return;
    for (int i = start; i < numsSize; ++i)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > target)
            return;
        tmp[len] = nums[i];
        combination(nums, numsSize, target - nums[i], i + 1, len + 1, tmp, ans,
                    idx, rcs);
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
                      int *returnSize, int **returnColumnSizes)

{
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int **ans = malloc(sizeof(int *) * 50);
    *returnColumnSizes = malloc(sizeof(int) * 50);
    int *tmp = malloc(sizeof(int) * candidatesSize);
    int idx = 0;
    combination(candidates, candidatesSize, target, 0, 0, tmp, ans, &idx,
                returnColumnSizes);
    *returnSize = idx;
    free(tmp);
    ans = realloc(ans, sizeof(int *) * idx);
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * idx);
    return ans;
}
