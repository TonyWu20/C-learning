
int singleNumber(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    int res = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        res ^= nums[i];
    }
    return res;
}
