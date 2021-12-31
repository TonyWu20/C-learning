#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSame(int *countS, int *countP)
{
    for (int i = 0; i < 26; ++i)
    {
        if (countP[i] != countS[i])
            return 0;
    }
    return 1;
}

void save(int **answer, int pos, int *returnSize)
{
    (*returnSize)++;
    (*answer)[*returnSize - 1] = pos;
    return;
}

int *findAnagrams(char *s, char *p, int *returnSize)
{
    int pLen = strlen(p);
    int sLen = strlen(s);
    if (sLen < pLen)
    {
        *returnSize = 0;
        return NULL;
    }
    int *answer = malloc(sizeof(int) * sLen);
    *returnSize = 0;
    int countP[26] = {0};
    int countS[26] = {0};
    for (int i = 0; i < pLen; ++i)
    {
        countP[p[i] - 'a']++;
    }
    for (int i = 0; i < sLen; ++i)
    {
        countS[s[i] - 'a']++;
        for (int j = 0; j < 26; ++j)
        {
            printf("%d%c", countS[j], (j < 25) ? ' ' : '\n');
        }
        if (i >= pLen - 1 && isSame(countS, countP))
        {
            int pos = i + 1 - pLen;
            save(&answer, pos, returnSize);
        }
        if (i >= pLen - 1)
        {
            countS[s[i + 1 - pLen] - 'a']--;
        }
    }
    return answer;
}

int main()
{
    char *s[] = {"cbaebabacd", "abab", "baa"};
    char *p[] = {"abc", "ab", "aa"};
    int tSize = sizeof(s) / sizeof(char *);
    int returnSize = 0;
    for (int i = 0; i < tSize; ++i)
    {
        int *ans = findAnagrams(s[i], p[i], &returnSize);
        printf("[");
        for (int j = 0; j < returnSize; ++j)
        {
            printf("%d%c", ans[j], (j < returnSize - 1) ? ',' : ']');
        }
        printf("\n");
        free(ans);
    }
    return 0;
}
