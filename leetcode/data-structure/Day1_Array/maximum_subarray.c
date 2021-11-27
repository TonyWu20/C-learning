#include <limits.h>
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max_triple(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxCrossArray(int *nums, int l, int m, int r)
{
    int sum = 0;
    int left_max = INT_MIN;
    for (int i = m; i >= l; --i)
    {
        sum += nums[i];
        left_max = max(left_max, sum);
    }
    sum = 0;
    int right_max = INT_MIN;
    for (int i = m + 1; i <= r; ++i)
    {
        sum += nums[i];
        right_max = max(right_max, sum);
    }
    return max_triple(left_max + right_max, left_max, right_max);
}

int maxPartArray(int *nums, int l, int r)
{
    if (l == r)
        return nums[l];
    int m = l + (r - l) / 2;
    return max_triple(maxPartArray(nums, l, m), maxPartArray(nums, m + 1, r),
                      maxCrossArray(nums, l, m, r));
}

int maxSubArray(int *nums, int numsSize)
{
    int l = 0;
    int r = numsSize - 1;
    return maxPartArray(nums, l, r);
}

int main(int argc, char *argv[])
{
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    printf("%d\n", maxSubArray(nums, numsSize));
    return 0;
}
