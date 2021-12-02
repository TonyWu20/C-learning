#include <stdio.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

bool checkInclusion(char *s1, char *s2)
{
    int s1Len = strlen(s1), s2Len = strlen(s2);
    if (s1Len > s2Len)
        return false;
    int s1Map[26] = {0};
    int s2Map[26] = {0};
    for (int i = 0; i < s1Len; ++i)
    {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;
    }
    // s1 [ab]
    // s2 [ei]dboaoo
    int count = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (s1Map[i] == s2Map[i])
            count++;
    } // count = 22
    for (int i = 0; i < s2Len - s1Len; ++i)
    {
        int l = s2[i] - 'a', r = s2[i + s1Len] - 'a';
        if (count == 26)
            return true;
        s2Map[r]++;
        if (s2Map[r] == s1Map[r])
            count++;
        if (s2Map[r] == s1Map[r] + 1)
            count--;
        s2Map[l]--;
        if (s2Map[l] == s1Map[l])
            count++;
        if (s2Map[l] == s1Map[l] - 1)
            count--;
    }
    return count == 26;
}
