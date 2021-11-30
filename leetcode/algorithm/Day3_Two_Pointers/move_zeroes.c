void moveZeroes(int *nums, int numsSize)
{
    int nonZeroPos = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != 0)
        {
            nums[nonZeroPos] = nums[i];
            if (nonZeroPos != i)
                nums[i] = 0; // swap nonzero value and zero
            nonZeroPos++;    // move nonZeroPos pointer up
        }
    }
}
