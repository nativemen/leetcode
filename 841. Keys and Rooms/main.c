#include <stdbool.h>
#include <stdio.h>

static void dfs(int **rooms, int roomsSize, int *roomsColSize, int index, int *visited) {
    if (index < 0 || index >= roomsSize || visited[index]) {
        return;
    }

    visited[index] = true;

    for (int i = 0; i < roomsColSize[index]; i++) {
        dfs(rooms, roomsSize, roomsColSize, rooms[index][i], visited);
    }
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize) {
    bool visited[roomsSize];

    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    dfs(rooms, roomsSize, roomsColSize, 0, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}