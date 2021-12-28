#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes)
{
    if (!nums || numsSize < 3)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int count = 0;
    int **res = NULL;

    for (int i = 0; i < numsSize; ++i)
    {
        int start = i + 1;
        int end = numsSize - 1;
        int sum;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        while (start < end)
        {
            sum = nums[i] + nums[start] + nums[end];
            if (sum == 0)
            {
                count++;
                res = realloc(res, sizeof(int *) * count);
                res[count - 1] = malloc(sizeof(int) * 3);
                res[count - 1][0] = nums[i];
                res[count - 1][1] = nums[start];
                res[count - 1][2] = nums[end];
                while (start < end && nums[start] == nums[start + 1])
                    start++;
                while (start < end && nums[end] == nums[end - 1])
                    end--;
                start++;
                end--;
            }
            else if (sum > 0)
                end--;
            else
                start++;
        }
    }
    *returnSize = count;
    *returnColumnSizes = malloc(sizeof(int) * count);
    for (int i = 0; i < count; ++i)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return res;
}
