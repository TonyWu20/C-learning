#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false,
    true
} bool;

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int r, c, value, check[3][9][10] = {0};
    for (r = 0; r < 9; ++r)
    {
        for (c = 0; c < 9; ++c)
        {
            value = board[r][c] - '0';
            if (value != -2) /* exclude '.' */
            {
                if (check[0][r][value]++ > 0)
                    return false;
                if (check[1][c][value]++ > 0)
                    return false;
                if (check[2][(r / 3) * 3 + c / 3][value]++ > 0)
                    return false;
            }
        }
    }
    return true;
}
bool isValidSudoku2(char **board, int boardSize, int *boardColSize)
{
    int r = boardSize, c = *boardColSize;
    // check rows
    for (int i = 0; i < r; ++i)
    {
        int checktab[10] = {0};
        for (int j = 0; j < c; ++j)
        {
            char bVal = board[i][j];
            int val = (bVal == '.') ? 0 : bVal - '0';
            if (val > 0 && checktab[val]++ > 0)
                return false;
        }
    }
    for (int j = 0; j < c; ++j)
    {
        int checktab[10] = {0};
        for (int i = 0; i < r; ++i)
        {
            char bVal = board[i][j];
            int val = (bVal == '.') ? 0 : bVal - '0';
            if (val > 0 && checktab[val]++ > 0)
                return false;
        }
    }
    for (int k = 0; k < r; ++k)
    {
        int checktab[10] = {0};
        int cRowStart = (k / 3) * 3;
        int cRowLimit = cRowStart + 3;
        int cColStart = (k % 3) * 3;
        int cColLimit = cColStart + 3;
        for (int i = cRowStart; i < cRowLimit; ++i)
        {
            for (int j = cColStart; j < cColLimit; ++j)
            {
                char bVal = board[i][j];
                int val = (bVal == '.') ? 0 : bVal - '0';
                if (val > 0 && checktab[val]++ > 0)
                    return false;
            }
        }
    }
    return true;
}
