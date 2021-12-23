#include <stdio.h>
#include <stdlib.h>

int countWaysDP(int n)
{
    int res[n];
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        res[i] = 0;
        for (int j = 1; j <= 2 && j <= i; ++j)
        {
            res[i] += res[i - j];
        }
    }
    return res[n - 1];
}

int climbStairs(int n)
{
    int res[n + 1];
    res[0] = res[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        res[i] = 0;
        for (int j = 1; j <= 2 && j <= i; ++j)
        {
            res[i] += res[i - j];
        }
    }
    return res[n];
}

int main(int argc, char *argv[])
{
    int n = 3;
    printf("%d\n", climbStairs(n));
    return 0;
}
