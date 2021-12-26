#include <stdio.h>
#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
  int *ret = malloc(sizeof(int) * 2);
  *returnSize = 2;
  ret[0] = -1;
  ret[1] = -1;
  if (numsSize < 1)
    return ret;
  int left = 0, right = numsSize - 1;
  while (left <= right) {
    if (nums[left] < target) {
      left++;
    } else if (nums[left] == target) {
      ret[0] = left;
    }
    if (nums[right] > target) {
      right--;
    } else if (nums[right] == target) {
      ret[1] = right;
    }
    if (ret[0] != -1 && ret[1] != -1)
      return ret;
  }
  return ret;
}
