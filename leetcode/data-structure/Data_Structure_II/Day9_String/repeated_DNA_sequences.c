#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1048576
#define H 262144

struct Pair
{
    int hash;
    int index;
};

int cmp(const void *a, const void *b)
{
    const struct Pair *a1 = a;
    const struct Pair *b1 = b;
    return a1->hash - b1->hash;
}
char **findRepeatedDnaSequences(char *s, int *returnSize)
{
    int sLen = strlen(s);
    if (sLen < 10)
    {
        *returnSize = 0;
        return NULL;
    }
    struct Pair P[sLen];
    memset(P, 0, sizeof(struct Pair) * sLen);
    int map[26] = {0};
    map['A' - 'A'] = 0;
    map['T' - 'A'] = 1;
    map['C' - 'A'] = 2;
    map['G' - 'A'] = 3;
    P[0].index = 0;
    int i;
    for (i = 0; i < 10; ++i)
    {
        P[0].hash = P[0].hash * 4 + map[s[i] - 'A'];
    }
    int j = 1;
    for (; i < sLen; i++)
    {
        P[j].hash = P[j - 1].hash - H * map[s[i - 10] - 'A'];
        P[j].hash = P[j].hash * 4 + map[s[i] - 'A'];
        P[j].index = j;
        j++;
    }
    qsort(P, j, sizeof(struct Pair), cmp);
    int count = 1;
    char **ans = malloc(sLen * sizeof(char *));
    *returnSize = 0;
    for (i = 1; i < j; i++)
    {
        if (P[i].hash == P[i - 1].hash)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                (*returnSize)++;
                ans[*returnSize - 1] = malloc(11 * sizeof(char));
                memcpy(ans[*returnSize - 1], &s[P[i - 1].index], 10);
                ans[*returnSize - 1][10] = 0;
            }
            count = 1;
        }
    }
    if (count > 1)
    {
        (*returnSize)++;
        ans[*returnSize - 1] = malloc(11 * sizeof(char));
        memcpy(ans[*returnSize - 1], &s[P[j - 1].index], 10);
        ans[*returnSize - 1][10] = 0;
    }
    return ans;
}
int main(int argc, char *argv[])
{
    char s[] = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    int returnSize = 0;
    findRepeatedDnaSequences(s, &returnSize);
    return 0;
}
