#include <string.h>

int countDecode(char *s, int n)
{
    if (*s == '0')
        return 0;
    int count[n + 1];
    count[0] = 1;
    count[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        count[i] = 0;
        if (s[i - 1] > '0')
            count[i] = count[i - 1];
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
            count[i] += count[i - 2];
    }
    return count[n];
}

int numDecodings(char *s)
{
    int sLen = strlen(s);
    if (sLen < 1 || *s == '0')
        return 0;
    int count = countDecode(s, sLen);
    return count;
}
