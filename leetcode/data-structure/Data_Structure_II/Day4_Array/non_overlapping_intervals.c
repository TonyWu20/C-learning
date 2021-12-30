#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} interval;
int cmpfunc(const void *a, const void *b)
{
    return ((interval *)a)->end - ((interval *)b)->end;
}
int eraseOverlapIntervals(int **intervals, int intervalsSize,
                          int *intervalsColSize)
{
    if (intervalsSize == 1)
        return 0;
    interval *ints = malloc(sizeof(interval) * intervalsSize);
    for (int i = 0; i < intervalsSize; ++i)
    {
        ints[i].start = intervals[i][0];
        ints[i].end = intervals[i][1];
    }
    qsort(ints, intervalsSize, sizeof(interval), cmpfunc);
    int count = 0;
    int start = 0, end = 1;
    while (start < intervalsSize - 1 && end < intervalsSize)
    {
        if (ints[start].end > ints[end].start)
            count++;
        else
            start = end;
        end++;
    }
    return count;
}
