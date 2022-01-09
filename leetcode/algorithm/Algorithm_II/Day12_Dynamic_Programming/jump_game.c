typedef enum
{
    false,
    true
} bool;

bool canJump(int *nums, int numsSize)
{
    int i, max;
    max = 0;
    for (i = 0; i < numsSize - 1 && max < numsSize; ++i)
    {
        max = (i + nums[i] > max) ? i + nums[i] : max;
        if (max < i + 1) // cannot reach next one pos
            return false;
    }
    return true;
}
