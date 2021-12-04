#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findNumbers(int *nums, int numsSize)
{
    int count = 0;
    int check = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        int num = nums[i];
        if (num == 0)
            count++;
        while (num > 0)
        {
            check++;
            num /= 10;
        }
        if (check % 2 == 0)
            count++;
        check = 0;
    }
    return count;
}

int main(int argc, char *argv[])
{
    int nums[] = {12, 345, 2, 6, 7896};
    int numsSize = sizeof(nums) / sizeof(int);
    printf("%d\n", findNumbers(nums, numsSize));
    return 0;
}
