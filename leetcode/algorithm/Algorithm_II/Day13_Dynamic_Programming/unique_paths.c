#include <stdlib.h>
#include <string.h>

int uniquePaths(int m, int n)
{
    int paths[m * n];
    memset(paths, 0, m * n * sizeof(int));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || j == 0)
                paths[i * n + j] = 1;
            else
                paths[i * n + j] +=
                    paths[(i - 1) * n + j] + paths[i * n + j - 1];
        }
    }
    return paths[m * n - 1];
}
