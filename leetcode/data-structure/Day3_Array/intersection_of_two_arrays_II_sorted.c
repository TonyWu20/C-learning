#include <stdio.h>
#include <stdlib.h>
#define PRIME 1921

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b);
}

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    int *ret = malloc(sizeof(int));
    *returnSize = 0;
    /* Define which array to start first */
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else
        {
            ret = realloc(ret, sizeof(int) * (*returnSize + 1));
            ret[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int nums1[2] = {1, 2};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2[2] = {2, 2};
    int nums2Size = sizeof(nums2) / sizeof(int);
    int returnSize = 0;
    int *ret;
    ret = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);
    if (ret)
    {
        printf("[");
        for (int i = 0; i < returnSize; ++i)
        {
            printf("%d%s", ret[i], (i == returnSize - 1) ? "]\n" : ",");
        }
    }
    free(ret);
    return 0;
}
