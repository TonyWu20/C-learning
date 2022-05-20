/***********************************************************************
 * The problem is actually sorting an array of multiple 0, 1, 2 in-place
 * Use quicksort to do it
 ***********************************************************************/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int *nums, int l, int r)
{
    if (l >= r || l < 0)
        return;
    int pivot = (l + r) / 2;
    swap(nums + l, nums + pivot);
    int last = l;
    for (int i = last + 1; i <= r; ++i)
    {
        if (nums[i] < nums[l])
        {
            last++;
            swap(nums + i, nums + last);
        }
    }
    swap(nums + l, nums + last);
    quickSort(nums, l, last - 1);
    quickSort(nums, last + 1, r);
}
void sortColors(int *nums, int numsSize)
{
    quickSort(nums, 0, numsSize - 1);
}
