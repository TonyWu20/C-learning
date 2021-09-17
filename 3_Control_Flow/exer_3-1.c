/* binary search with one test in loop */
#include <stdio.h>
#include <time.h>
#define SIZE 1 << 25

int binsearch(int x, int v[], int n);  /* two tests */
int binsearch2(int x, int v[], int n); /* one test */
int values[SIZE];

int main(void)
{
    int i, n = SIZE;
    clock_t time_taken;

    for (i = 0; i < SIZE; i++)
        values[i] = i;
    for (i = 0, time_taken = clock(); i < n; i++)
        binsearch(i, values, SIZE);
    time_taken = clock() - time_taken;
    printf("binsearch:\n");
    /* Test binsearch version 1 */
    printf("binsearch took %lu clocks (%lu seconds)\n",
           (unsigned long)time_taken,
           (unsigned long)time_taken / CLOCKS_PER_SEC);
    /* Test binsearch version 2 */
    for (i = 0, time_taken = clock(); i < SIZE; i++)
        binsearch2(i, values, SIZE);
    time_taken = clock() - time_taken;
    printf("binsearch2:\n");
    printf("binsearch2 took %lu clocks (%lu seconds)\n",
           (unsigned long)time_taken,
           (unsigned long)time_taken / CLOCKS_PER_SEC);
}
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* match */
            return mid;
    }
    return -1; /* no match */
}
int binsearch2(int x, int v[], int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    if (x == v[low])
        return low;
    else
        return -1;
}
