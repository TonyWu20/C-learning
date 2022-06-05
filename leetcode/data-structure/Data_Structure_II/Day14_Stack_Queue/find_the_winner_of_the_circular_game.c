
int findTheWinner(int n, int k)
{
    int i;
    int arr[n];
    int c = 0, c1;
    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    i = 0;
    while (c < n - 1)
    {
        c1 = 0;
        while (c1 != k)
        {
            if (arr[i] != 0)
            {
                c1++;
                if (c1 == k)
                {
                    arr[i] = 0;
                    c++;
                }
                i++;
                if (i >= n)
                    i = 0;
            }
            else
            {
                i++;
                if (i >= n)
                    i = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i])
            return arr[i];
    }
    return 1;
}
