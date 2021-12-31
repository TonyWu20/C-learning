
int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
    if (k <= 1)
        return 0;
    int prod = 1;
    int ans = 0, left = 0;
    for (int right = 0; right < numsSize; right++)
    {
        prod *= nums[right];
        while (prod >= k)
            prod /= nums[left++];
        ans += right - left + 1;
    }
    return ans;
}
