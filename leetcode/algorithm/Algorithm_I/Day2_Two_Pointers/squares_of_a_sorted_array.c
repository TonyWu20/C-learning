#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int lo = 0;
    int hi = numsSize - 1;
    int ptr = numsSize - 1;
    int *res = malloc(numsSize * sizeof(int));
    while (lo <= hi)
    {
        if (abs(nums[lo]) > abs(nums[hi]))
        {
            res[ptr--] = nums[lo] * nums[lo];
            lo++;
        }
        else
        {
            res[ptr--] = nums[hi] * nums[hi];
            hi--;
        }
    }
    *returnSize = numsSize;
    return res;
}
