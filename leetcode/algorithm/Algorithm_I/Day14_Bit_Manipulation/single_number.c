int singleNumber(int *nums, int numsSize)
{
    int accmulator = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        accmulator ^= nums[i];
    }
    return accmulator;
}
/**
 * X ^ X = 0; X ^ 0 = X;
 * X ^ Y ^ Y = X;
 * [1,2,1,4,2] = 1^2^1^4^2 = 4^1^2^1^2 = 4;
 * 0001 ^ 0010 = 0011 = 3;
 * 0011 ^ 0001 = 0010 = 2;
 * 0010 ^ 0100 = 0110 = 6;
 * 0110 ^ 0010 = 0100 = 4;
 */
