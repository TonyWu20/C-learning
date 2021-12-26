#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void storeArr(int *nums, int numsSize, int ***arr, int *returnSize)
{
    (*returnSize)++;
    *arr = realloc(*arr, sizeof(int *) * (*returnSize));
    (*arr)[*returnSize - 1] = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i)
    {
        (*arr)[*returnSize - 1][i] = nums[i];
    }
    return;
}

void search(int *nums, int numsSize, int ***arr, int *returnSize, int start,
            int end)
{
    if (start == end)
    {
        storeArr(nums, numsSize, arr, returnSize);
        return;
    }
    for (int i = start; i <= end; ++i)
    {
        swap(nums + i, nums + start);
        search(nums, numsSize, arr, returnSize, start + 1, end);
        swap(nums + i, nums + start);
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int **ret = malloc(sizeof(int *));
    *returnSize = 0;
    search(nums, numsSize, &ret, returnSize, 0, numsSize - 1);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ret;
}
