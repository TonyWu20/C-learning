#include <stdio.h>
#include <stdlib.h>

int rob(int *nums, int numsSize)
{
    int val1, val2, max_val;
    max_val = 0;
    switch (numsSize)
    {
    case 0:
        return 0;
    case 1:
        return nums[0];
    case 2:
        return (nums[1] > nums[0]) ? nums[1] : nums[0];
    default:
    {
        val1 = nums[0];
        val2 = (nums[1] > nums[0]) ? nums[1] : nums[0];
        for (int i = 2; i < numsSize; ++i)
        {
            max_val = ((val1 + nums[i]) > val2) ? (val1 + nums[i]) : val2;
            val1 = val2;
            val2 = max_val;
        }
        break;
    }
    }
    return max_val;
}
