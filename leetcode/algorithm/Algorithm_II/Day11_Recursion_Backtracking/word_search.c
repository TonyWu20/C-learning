#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;

bool search(char **board, int rowSize, int colSize, int i, int j, char *word)
{
    if (*word == 0)
        return true;
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize)
        return false;
    if (board[i][j] != *word)
        return false;
    char c = board[i][j];
    board[i][j] = ' ';
    if (search(board, rowSize, colSize, i + 1, j, word + 1) ||
        search(board, rowSize, colSize, i - 1, j, word + 1) ||
        search(board, rowSize, colSize, i, j + 1, word + 1) ||
        search(board, rowSize, colSize, i, j - 1, word + 1))
        return true;
    board[i][j] = c;
    return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < *boardColSize; ++j)
        {
            if (board[i][j] == *word)
            {
                if (search(board, boardSize, *boardColSize, i, j, word))
                    return true;
            }
        }
    }
    return false;
}
