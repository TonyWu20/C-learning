#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;
    // 先排序
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int unit = 5000;
    int **arr = (int **)malloc(sizeof(int *) * unit);
    *returnColumnSizes = (int *)malloc(sizeof(int) * unit);
    int i, l, r, target;
    for (i = 0; i < numsSize - 2; ++i)
    {
        if (nums[i] > 0)
            break;
        // avoid duplication
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        // nums[i] + target == 0
        target = -nums[i];
        l = i + 1;
        r = numsSize - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] < target)
                ++l;
            else if (nums[l] + nums[r] > target)
                --r;
            else
            {
                (*returnColumnSizes)[*returnSize] = 3;
                arr[*returnSize] = (int *)malloc(sizeof(int) * 3);
                arr[*returnSize][0] = nums[i];
                arr[*returnSize][1] = nums[l++];
                arr[(*returnSize)++][2] = nums[r--];
                if (*returnSize == unit)
                {
                    unit <<= 1;
                    arr = (int **)realloc(arr, sizeof(int *) * unit);
                    *returnColumnSizes =
                        (int *)realloc(*returnColumnSizes, sizeof(int) * unit);
                }
                // avoid duplication
                while (l < r && nums[l] == nums[l - 1])
                    ++l;
                // avoid duplication
                while (l < r && nums[r] == nums[r + 1])
                    --r;
            }
        }
    }
    return arr;
}
