#include <stdio.h>

int findMin(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return (nums[0] < nums[1]) ? nums[0] : nums[1];
    int start = 0, end = numsSize - 1;
    if (nums[end] > nums[start])
        return nums[0];
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (nums[mid - 1] > nums[mid])
            return nums[mid];
        if (nums[mid] > nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
