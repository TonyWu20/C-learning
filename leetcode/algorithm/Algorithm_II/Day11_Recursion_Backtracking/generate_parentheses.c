#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

long long calculateSize(int n)
{
    long long upper = factorial(2 * n);
    long long below = factorial(n) * factorial(n + 1);
    return upper / below;
}

void backTrack(char *tmp, int open, int close, int len, int max, char **ans,
               int *idx)
{
    if (len == max * 2)
    {
        tmp[len] = 0;
        ans[*idx] = strdup(tmp);
        (*idx)++;
        return;
    }
    if (open < max)
    {
        tmp[len] = '(';
        backTrack(tmp, open + 1, close, len + 1, max, ans, idx);
    }
    if (close < open)
    {
        tmp[len] = ')';
        backTrack(tmp, open, close + 1, len + 1, max, ans, idx);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    long long ansSize = calculateSize(n);
    char **ans = malloc(sizeof(*ans) * ansSize);
    int idx = 0;
    char *tmp = malloc(sizeof(char) * (2 * n + 1));
    backTrack(tmp, 0, 0, 0, n, ans, &idx);
    *returnSize = ansSize;
    return ans;
}
