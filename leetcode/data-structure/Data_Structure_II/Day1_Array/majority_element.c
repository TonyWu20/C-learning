#include <stdio.h>
#include <stdlib.h>

int majorityElement(int *nums, int numsSize)
{
    int count = 0;
    int candidate = nums[0];
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] == candidate)
            count++;
        else
            count--;
        if (count == 0)
            candidate = nums[i + 1];
    }
    return candidate;
}
