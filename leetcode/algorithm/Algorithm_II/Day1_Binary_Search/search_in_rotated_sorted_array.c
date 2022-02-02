#include <stdio.h>

int binarySearch(int *nums, int l, int r, int target)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[l] <= nums[mid])
    {
        if (target >= nums[l] && target <= nums[mid])
        {
            return binarySearch(nums, l, mid - 1, target);
        }
        return binarySearch(nums, mid + 1, r, target);
    }
    if (target >= nums[mid] && target <= nums[r])
        return binarySearch(nums, mid + 1, r, target);
    return binarySearch(nums, l, mid - 1, target);
}

int search(int *nums, int numsSize, int target)
{
    return binarySearch(nums, 0, numsSize - 1, target);
}
