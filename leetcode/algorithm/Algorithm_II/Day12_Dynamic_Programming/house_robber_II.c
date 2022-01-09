#include <stdio.h>
int rob(int *nums, int numsSize)
{
    int pre, cur, tmp;
    int i, j, max = 0;
    switch (numsSize)
    {
    case 0:
        return 0;
    case 1:
        return nums[0];
    case 2:
        return (nums[0] > nums[1]) ? nums[0] : nums[1];
    default:
    {
        for (j = 0; j < 3; ++j)
        {
            pre = cur = nums[j];
            for (i = j + 2; i < (numsSize - (!j)); ++i)
            {
                tmp = (cur > pre + nums[i]) ? cur : pre + nums[i];

                pre = cur;
                cur = tmp;
            }
            max = max > cur ? max : cur;
        }
    }
    }
    return max;
}
