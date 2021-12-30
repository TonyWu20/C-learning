#include <stdlib.h>
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *answer = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int prod = 1;
    for (int i = 0; i < numsSize; i++)
    {
        answer[i] = prod;
        prod *= nums[i];
    }
    prod = 1;
    for (int i = numsSize - 1; i >= 0; --i)
    {
        answer[i] *= prod;
        prod *= nums[i];
    }
    return answer;
}
