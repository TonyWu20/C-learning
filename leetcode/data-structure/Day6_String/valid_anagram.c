#include <string.h>
typedef enum
{
    false,
    true
} bool;

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int alphaMap[26] = {0};
    for (int i = 0; s[i] != '\0'; ++i)
    {
        alphaMap[s[i] - 'a']++;
    }
    for (int i = 0; t[i] != '\0'; ++i)
    {
        if (--alphaMap[t[i] - 'a'] < 0)
            return false;
    }
    return true;
}
