#include <stdlib.h>
typedef enum
{
    false,
    true
} bool;
struct Point
{
    int x;
    int y;
};

bool isValid(char **board, int rowSize, int colSize, int i, int j)
{
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize)
        return false;
    if (i - 1 >= 0)
}

void search(char **board, int rowSize, int colSize, int i, int j,
            struct Point *q, int *front, int *rear)
{
    q[(*rear)++].x = i;
    q[(*rear)].y = j;
    board[i][j] = '-';
    int old_front = *front;
    while (*front <= *rear)
    {
        struct Point currPoint = q[*front];
        int x, y;
        x = currPoint.x;
        y = currPoint.y;
        // If reach to the boarder, than the recorded region is not valid,
        // revert to original
        if (x == 0 || x == rowSize - 1 || y == 0 || y == colSize - 1)
        {
            for (int i = old_front; i < (*rear); ++i)
            {
                board[q[i].x][q[i].y] = 'O';
            }
            return; // Quit
        }
        (*front)++;
        if (x - 1 >= 0 && board[x - 1][y] == 'O')
        {
            q[(*rear)++].x = x - 1;
            q[(*rear)].y = y;
            board[x - 1][y] = '-';
        }
        if (x + 1 < rowSize && board[x + 1][y] == 'O')
        {
            q[(*rear)++].x = x + 1;
            q[(*rear)].y = y;
            board[x + 1][y] = '-';
        }
    }
}
void solve(char **board, int boardSize, int *boardColSize)
{
    int queueSize = boardSize * (*boardColSize);
    struct Point *q = malloc(sizeof(struct Point) * queueSize);
    int front = 0, rear = 0;
    int curr_front, curr_rear;
    curr_front = front;
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < *boardColSize; ++j)
        {
            if (board[i][j] == 'O')
            {
                q[++rear].x = i;
                q[rear].y = j;
                board[i][j] = '-';
            }
        }
    }
}
