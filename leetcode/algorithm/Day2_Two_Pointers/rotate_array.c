
void rotate(int *nums, int numsSize, int k)
{
    int i;
    k = (numsSize < k) ? (k % numsSize) : k;
    if (k >= 1)
    {
        int temp[k];
        for (i = 0; i < k; i++)
        {
            temp[i] = nums[numsSize - k + i];
        }
        for (i = numsSize - 1; i - k >= 0; --i)
        {
            nums[i] = nums[i - k];
        }
        for (i = 0; i < k; ++i)
        {
            nums[i] = temp[i];
        }
    }
    else
    {
        ;
    }
}
