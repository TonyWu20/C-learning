#include <stdio.h>

int numberOfArithmeticSlices(int *nums, int numsSize)
{
    if (numsSize < 3)
        return 0;
    int curDiff, prevDiff;
    int count = 0, start = 0;
    int len = 1, ptr = 1;
    while (start < numsSize - 2 && ptr < numsSize)
    {
        if (ptr == start + 1)
        {
            curDiff = prevDiff = nums[ptr] - nums[start];
            len++;
            ptr++;
        }
        else
        {
            curDiff = nums[ptr] - nums[ptr - 1];
            if (curDiff != prevDiff)
            {
                start = ptr - 1;
                ptr = start + 1;
                len = 1;
                prevDiff = curDiff;
            }
            else
            {
                len++;
                count += len - 3 + 1;
                ptr++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int nums[] = {1, 2, 3, 4, 5};
    printf("%d\n", numberOfArithmeticSlices(nums, sizeof(nums) / sizeof(int)));
    return 0;
}
