#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long A(int n, int k)
{
    int i = n - k + 1;
    unsigned long long ret = 1;
    while (i <= n)
    {
        ret *= i++;
    }
    return ret;
}

void backTracing(int **res, int *result_ind, int *curr_result,
                 int curr_result_ind, int curr_result_len, int start, int end)
{
    if (curr_result_ind == curr_result_len)
    {
        memcpy(res[*result_ind], curr_result, curr_result_len * sizeof(int));
        (*result_ind)++;
        return;
    }
    for (int i = start; i <= end; ++i)
    {
        curr_result[curr_result_ind] = i;
        backTracing(res, result_ind, curr_result, curr_result_ind + 1,
                    curr_result_len, i + 1, end);
    }
}
int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    int result_ind = 0;
    int lower = 1, upper = 1;
    *returnSize = upper / lower;
    int *curr_result = malloc(sizeof(int) * k);
    int **res = malloc(sizeof(*res) * (*returnSize));
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i)
    {
        res[i] = malloc(sizeof(int) * k);
        (*returnColumnSizes)[i] = k;
    }
    backTracing(res, &result_ind, curr_result, 0, k, 1, n);
    return res;
}
