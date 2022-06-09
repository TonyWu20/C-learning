void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int removeElement(int *nums, int numsSize, int val)
{
    if (numsSize == 1 && nums[0] == val)
        return 0;
    int tail = numsSize - 1;
    int i = 0;
    int k = 0;
    for (; i < numsSize; ++i)
    {
        if (nums[i] == val)
        {
            while (nums[tail] == val && tail > i)
                tail--;
            swap(&nums[i], &nums[tail]);
            k++;
        }
    }
    if (k > 0)
    {
        return tail;
    }
    return tail + 1;
}

// Another

int removeElement_2(int *nums, int numsSize, int val)
{
    int i = 0;
    while (i < numsSize)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[numsSize - 1];
            numsSize--;
        }
        else
            i++;
    }
    return numsSize;
}
