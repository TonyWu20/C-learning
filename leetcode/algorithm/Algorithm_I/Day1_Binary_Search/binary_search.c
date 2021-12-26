#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    int mid = left + (right - left) / 2; /* divide the array by 2 */
    while (left <= right)
    {
        if (nums[mid] == target) /* target at mid */
            return mid;
        if (nums[mid] > target) /* target at the left of mid */
        {
            right = mid - 1;
            mid = left + (right - left) / 2;
        }
        if (nums[mid] < target) /* target at the right of mid */
        {
            left = mid + 1;
            mid = left + (right - left) / 2;
        }
    }
    return -1;
}
