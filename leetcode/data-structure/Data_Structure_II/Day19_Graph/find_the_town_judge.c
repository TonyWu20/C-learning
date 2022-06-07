
int findJudge(int n, int **trust, int trustSize, int *trustColSize){
    if (!trust)
        return -1;

    int *check = calloc(n, sizeof(int));
    for (int i = 0; i < trustSize; ++i)
    {
        check[trust[i][0] - 1]--;
        check[trust[i][1] - 1]++;
    }
    int judge= -1;
    for (int i = 0; i < n; ++i)
    {
        if (check[i] == n-1)
        {
            judge = i + 1;
        }
    }
    free(check);
    return judge;
}
