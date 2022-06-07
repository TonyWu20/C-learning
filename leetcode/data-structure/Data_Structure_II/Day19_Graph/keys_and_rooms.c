#include <stdbool.h>
#include <string.h>

void visitRoom(int **rooms, bool *visited, int room_num, int *roomsColSize)
{
    if (visited[room_num])
        return;
    visited[room_num] = true;
    for (int i = 0; i < roomsColSize[room_num]; ++i)
    {
        if (visited[rooms[room_num][i]])
            continue;
        visitRoom(rooms, visited, rooms[room_num][i], roomsColSize);
    }
}
bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    bool visited[roomsSize];
    for (int i = 0; i < roomsSize; ++i)
    {
        visited[i] = false;
    }
    visitRoom(rooms, visited, 0, roomsColSize);
    for (int i = 0; i < roomsSize; ++i)
    {
        if (!visited[i])
            return false;
    }
    return true;
}
