#include <stdio.h>
#define ADDRESS 0
#if ADDRESS
int lengthOfLongestSubstring(char *s)
{
    char *checkAddr[128] = {NULL};
    char *tmp, *start = s;
    int curLen = 0;
    while (*start)
    {
        tmp = checkAddr[*s];
        checkAddr[*s] = start;
        if (tmp >= s)
        {
            curLen = (curLen > (start - s)) ? curLen : start - s;
            s = tmp + 1; // slide the window to exclude the last appearance of
                         // the letter
        }
        start++;
    }
    curLen = (curLen > (start - s)) ? curLen : start - s;
    return curLen;
}
#else
int lengthOfLongestSubstring(char *s)
{
    int curLen = 0, maxLen = 0, prevMaxLen = 0;
    int prevIdOfChar[128] = {0};
    for (char *c = s; *c; ++c)
    {
        int idx = c - s + 1;
        int possibleLen = idx - prevIdOfChar[*c];
        curLen = (++prevMaxLen < possibleLen) ? prevMaxLen : possibleLen;
        prevIdOfChar[*c] = idx;
        maxLen = (curLen > maxLen) ? curLen : maxLen;
        prevMaxLen = curLen;
    }
    return maxLen;
}
#endif
