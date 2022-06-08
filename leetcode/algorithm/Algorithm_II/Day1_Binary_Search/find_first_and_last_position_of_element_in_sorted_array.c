#include <stdio.h>
#include <stdlib.h>

int lowerBound(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target < nums[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return right - 1;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    ret[0] = -1;
    ret[1] = -1;
    if (numsSize < 1)
        return ret;
    int lower = lowerBound(nums, numsSize, target);
    int upper = upperBound(nums, numsSize, target);
    if (lower > upper)
        return ret;
    ret[0] = lower;
    ret[1] = upper;
    return ret;
}
