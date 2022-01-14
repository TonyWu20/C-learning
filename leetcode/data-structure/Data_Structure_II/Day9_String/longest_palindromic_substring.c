#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expandCenter(char *s, int sLen, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < sLen && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}
char *longestPalindrome(char *s)
{
    int sLen;
    if (!s || (sLen = strlen(s)) < 1)
        return "";
    int start = 0, end = 0;
    for (int i = 0; i < sLen; ++i)
    {
        int len1 = expandCenter(s, sLen, i, i);
        int len2 = expandCenter(s, sLen, i, i + 1);
        int len = (len1 > len2) ? len1 : len2;
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    int ansSize = end - start + 1;
    char *ans = malloc(sizeof(char) * (ansSize + 1));
    strncpy(ans, s + start, ansSize);
    ans[ansSize] = 0;
    return ans;
}
