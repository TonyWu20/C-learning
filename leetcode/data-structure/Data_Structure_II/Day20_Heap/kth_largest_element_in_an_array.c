#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int max(int *nums, int numsSize, int i, int left, int right)
{
    int largest = i;
    if (left < numsSize && nums[left] > nums[largest])
        largest = left;
    if (right < numsSize && nums[right] > nums[largest])
        largest = right;
    return largest;
}

void heapify(int *nums, int numsSize, int i)
{
    while (1)
    {
        int j = max(nums, numsSize, i, 2 * i + 1, 2 * i + 2);
        if (j == i)
            break;
        swap(&nums[i], &nums[j]);
        i = j;
    }
}

void heapSort(int *nums, int numsSize)
{
    int i;
    for (i = (numsSize - 2) / 2; i >= 0; i--)
    {
        heapify(nums, numsSize, i);
    }
    for (i = 0; i < numsSize; i++)
    {
        swap(&nums[0], &nums[numsSize - i - 1]);
        heapify(nums, numsSize - i - 1, 0);
    }
}

int findKthLargest(int *nums, int numsSize, int k)
{
    if (numsSize == 0 || k > numsSize)
        return 0;
    heapSort(nums, numsSize);
    return nums[numsSize - k];
}
