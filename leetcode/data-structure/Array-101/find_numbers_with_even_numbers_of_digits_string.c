#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findNumbers(int *nums, int numsSize)
{
    int count = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        char buffer[100000];
        sprintf(buffer, "%d", nums[i]);
        int len = strlen(buffer);
        if (len % 2 == 0)
            count++;
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
