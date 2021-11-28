/** Given a sorted array of distinct integers and a target value, return the
 *  index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 */
#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    if (numsSize == 1)
    {
        return (target <= nums[0]) ? 0 : 1;
    }
    int left = 0, right = numsSize - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (target == nums[mid])
            return mid;
        if (nums[mid] > target)
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        if (nums[mid] < target)
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }
    return (left >= right) ? left : right;
}

int main(int argc, char *argv[])
{
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 2;
    printf("target:%d, %d\n", target, searchInsert(nums, numsSize, target));
    printf("target:%d, %d\n", 0, searchInsert(nums, numsSize, 0));
    printf("target:%d, %d\n", 5, searchInsert(nums, numsSize, 5));
    printf("target:%d, %d\n", 7, searchInsert(nums, numsSize, 7));
    return 0;
}
