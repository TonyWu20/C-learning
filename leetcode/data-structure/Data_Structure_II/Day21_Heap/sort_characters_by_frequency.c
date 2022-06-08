#include <stdlib.h>
#include <string.h>

struct hashNode
{
    int id;
    int count;
};

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}
int cmph(const void *a, const void *b)
{
    return ((struct hashNode *)b)->count - ((struct hashNode *)a)->count;
}
char *frequencySort(char *s)
{
    struct hashNode arr[75] = {0};
    int i = 0;
    for (; s[i] != '\0'; ++i)
    {
        arr[s[i] - '0'].id = s[i];
        arr[s[i] - '0'].count++;
    }
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(struct hashNode), cmph);
    i = 0;
    for (int idx = 0; idx < 75 && arr[idx].count != 0; idx++)
    {
        for (int j = 0; j < arr[idx].count; ++j)
        {
            s[i++] = arr[idx].id;
        }
    }
    return s;
}
