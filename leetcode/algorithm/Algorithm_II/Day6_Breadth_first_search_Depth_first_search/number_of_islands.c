
void search(char **grid, int gridSize, int gridColSize, int r, int c)
{
    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1')
        search(grid, gridSize, gridColSize, r - 1, c);
    if (r + 1 < gridSize && grid[r + 1][c] == '1')
        search(grid, gridSize, gridColSize, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1')
        search(grid, gridSize, gridColSize, r, c + 1);
    if (c + 1 < gridColSize && grid[r][c + 1] == '1')
        search(grid, gridSize, gridColSize, r, c - 1);
}
int numIslands(char **grid, int gridSize, int *gridColSize)
{
    int row = gridSize;
    int col = *gridColSize;
    int ans = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                search(grid, row, col, i, j);
            }
        }
    }
    return ans;
}
