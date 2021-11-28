#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int squares(int val)
{
    return val * val;
}

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int *res = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = squares(nums[i]);
    }
    *returnSize = numsSize;
    int leftPtr = 0, rightPtr = numsSize - 1, ptr = numsSize - 1;
    /** The bigger values of the squared number in the original array are
     *  located in the beginning and the end. So traverse the res array from
     *  the end and put in the bigger value.
     */
    while (leftPtr <= rightPtr && ptr >= 0)
    {
        if (nums[leftPtr] < nums[rightPtr])
        {
            res[ptr--] = nums[rightPtr--];
        }
        else
        {
            res[ptr--] = nums[leftPtr++];
        }
    }
    return res;
}
