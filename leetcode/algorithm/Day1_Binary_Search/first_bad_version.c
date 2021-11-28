#include <stdio.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version)

typedef enum
{
    false,
    true
} bool;

bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int left, right, mid;
    left = 1;
    right = n;
    mid = left + (right - left) / 2;
    while (left < right)
    {
        if (isBadVersion(mid)) /* mid is bad, but not definitely the first */
        {
            right = mid; /* set right to mid to inspect the first half */
            mid = left + (right - left) / 2;
        }
        else /* mid is not bad, so set left to mid + 1 to inspect the second
                half */
        {
            left = mid + 1;
            mid = left + (right - left) / 2;
        }
    }
    return left; /* the loop will end when letf = right = firstBadVersion */
}
