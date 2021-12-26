/**
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 */
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int i1 = 0, i2 = numbersSize - 1;
    int *ret = malloc(sizeof(int) * 2);
    while (i1 < i2 < numbersSize)
    {
        int sum = numbers[i1] + numbers[i2];
        if (sum < target)
            i1++;
        else if (sum > target)
            i2--;
        else
        {
            ret[0] = ++i1;
            ret[1] = ++i2;
            *returnSize = 2;
            return ret;
        }
    }
    /* Not found */
    *returnSize = 0;
    return NULL;
}
