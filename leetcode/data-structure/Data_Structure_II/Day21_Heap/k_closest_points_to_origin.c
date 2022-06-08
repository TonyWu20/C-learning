#include <limits.h>
#include <stdlib.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#define BINARY
#ifndef BINARY
struct Point
{
    int x;
    int y;
    int dist;
    int id;
};

void splitDistance(struct Point *points, int *rems, int remainSize, int mid,
                   int *closer, int *closeSize, int *farther, int *farSize)
{
    for (int i = 0; i < remainSize; ++i)
    {
        if (points[rems[i]].dist <= mid)
        {
            closer[(*closeSize)++] = rems[i];
        }
        else
        {
            farther[(*farSize)++] = rems[i];
        }
    }
}
int **kClosest(int **points, int pointsSize, int *pointsColSize, int k,
               int *returnSize, int **returnColumnSizes)
{
    struct Point *p = malloc(sizeof(struct Point) * pointsSize);
    int pId[pointsSize];
    int *remaining;
    int remainCount = pointsSize;
    int lo = INT_MAX, hi = 0;
    for (int i = 0; i < pointsSize; ++i)
    {
        p[i].x = points[i][0];
        p[i].y = points[i][1];
        p[i].dist = p[i].x * p[i].x + p[i].y * p[i].y;
        p[i].id = i;
        pId[i] = i;
        lo = (lo < p[i].dist) ? lo : p[i].dist;
        hi = (hi > p[i].dist) ? hi : p[i].dist;
    }
    struct Point *closet = malloc(sizeof(struct Point) * k);
    int closetCount = 0;
    int closer[pointsSize];
    int closeSize = 0, farSize = 0;
    int farther[pointsSize];
    remaining = pId;

    while (k > 0)
    {
        int mid = (lo + hi) / 2;
        splitDistance(p, remaining, remainCount, mid, closer, &closeSize,
                      farther, &farSize);
        if (closeSize > k)
        {
            remaining = closer;
            remainCount = closeSize;
            hi = mid;
            closeSize = farSize = 0;
        }
        else
        {
            k -= closeSize;
            for (int i = 0; i < closeSize; ++i)
            {
                closet[closetCount++] = p[closer[i]];
            }
            remaining = farther;
            remainCount = farSize;
            lo = mid;
            closeSize = farSize = 0;
        }
    }
    k = closetCount;
    int **ret = malloc(sizeof(int *) * k);
    *returnSize = k;
    *returnColumnSizes = malloc(sizeof(int) * k);
    for (int i = 0; i < k; ++i)
    {
        ret[i] = malloc(sizeof(int) * 2);
        ret[i][0] = closet[i].x;
        ret[i][1] = closet[i].y;
        (*returnColumnSizes)[i] = 2;
    }
    free(closet);
    free(p);
    return ret;
}
#endif
// qsort
int cmp(const void *a, const void *b)
{
    const int *aa = *(int **)a;
    const int *bb = *(int **)b;
    return (aa[0] * aa[0] + aa[1] * aa[1]) - (bb[0] * bb[0] + bb[1] * bb[1]);
}
int **kClosest(int **points, int pointsSize, int *pointsColSize, int k,
               int *returnSize, int **returnColumnSizes)
{
    qsort(points, pointsSize, sizeof(int *), cmp);
    *returnSize = k;
    *returnColumnSizes = pointsColSize;
    return points;
}
