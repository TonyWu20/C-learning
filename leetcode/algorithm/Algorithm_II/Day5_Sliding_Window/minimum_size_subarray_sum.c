#include <limits.h>
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int min = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
        while (sum >= target)
        {
            min = (min < (i + 1 - left)) ? min : (i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (min != INT_MAX) ? min : 0;
}
