#include <stdlib.h>

void floodFill(char **board, int rowSize, int colSize, int i, int j)
{
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize)
        return;
    else if (board[i][j] == '-' || board[i][j] == 'X')
        return;
    else if (board[i][j] == 'O')
    {
        board[i][j] = '-';
        floodFill(board, rowSize, colSize, i - 1, j);
        floodFill(board, rowSize, colSize, i + 1, j);
        floodFill(board, rowSize, colSize, i, j + 1);
        floodFill(board, rowSize, colSize, i, j - 1);
    }
}

void solve(char **board, int boardSize, int *boardColSize)
{
    if (boardSize < 3 || *boardColSize < 3)
        return;
    int row, col;
    for (row = 0; row < boardSize; row++)
    {
        floodFill(board, boardSize, *boardColSize, row, 0);
        floodFill(board, boardSize, *boardColSize, row, *boardColSize - 1);
    }
    for (col = 0; col < *boardColSize; ++col)
    {
        floodFill(board, boardSize, *boardColSize, 0, col);
        floodFill(board, boardSize, *boardColSize, boardSize - 1, col);
    }
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < *boardColSize; ++j)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < *boardColSize; ++j)
        {
            if (board[i][j] == '-')
                board[i][j] = 'O';
        }
    }
}
