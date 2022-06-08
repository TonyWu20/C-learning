#include <stdio.h>
#include <stdlib.h>

struct hashNode
{
    int val;
    int freq;
};

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int cmph(const void *a, const void *b)
{
    return ((struct hashNode *)b)->freq - ((struct hashNode *)a)->freq;
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
    if (k == 0 || numsSize == 0 || numsSize < k)
    {
        *returnSize = 0;
        return NULL;
    }
    if (numsSize == k && k == 1)
    {
        *returnSize = 1;
        return nums;
    }
    int *ans = calloc(k, sizeof(int));
    struct hashNode hash[numsSize];
    for (int i = 0; i < numsSize; ++i)
    {
        hash[i].val = 0;
        hash[i].freq = 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int i, count = 0;
    hash[0].val = nums[0];
    hash[0].freq++;
    for (int i = 1; i < numsSize; ++i)
    {
        if (hash[count].val == nums[i])
        {
            hash[count].freq++;
        }
        else
        {
            hash[++count].val = nums[i];
            hash[count].freq++;
        }
    }
    qsort(hash, numsSize, sizeof(struct hashNode), cmph);
    for (i = 0; i < k; i++)
        ans[i] = hash[i].val;
    *returnSize = k;
    return ans;
}
