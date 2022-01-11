#include <stdlib.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;

bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
    int wordLen[wordDictSize];
    for (int i = 0; i < wordDictSize; ++i)
    {
        wordLen[i] = strlen(wordDict[i]);
    }
    int sLen = strlen(s);
    bool *arr = malloc(sizeof(bool) * sLen);
    for (int i = 0; i < sLen; ++i)
    {
        arr[i] = false;
        for (int j = 0; j < wordDictSize; ++j)
        {
            int candiLen = wordLen[j];
            if (candiLen > i + 1)
                continue;
            if (i + 1 != candiLen && arr[i - candiLen] == false)
                continue;
            if (!strncmp(&(s[i + 1 - candiLen]), wordDict[j], candiLen))
            {
                arr[i] = true;
                break;
            }
        }
    }
    bool result = arr[sLen - 1];
    free(arr);
    return result;
}
