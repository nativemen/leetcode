#include "uthash.h"
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

typedef struct {
    int room;
    UT_hash_handle hh;
} HashEntry;

static void dfs(int **rooms, int roomsSize, int *roomsColSize, int current, HashEntry **visited) {
    HashEntry *entry = NULL;

    HASH_FIND_INT(*visited, &current, entry);

    if (entry != NULL) {
        return;
    }

    entry = (HashEntry *)malloc(sizeof(HashEntry));
    if (entry == NULL) {
        return;
    }

    entry->room = current;

    HASH_ADD_INT(*visited, room, entry);

    for (int i = 0; i < roomsColSize[current]; i++) {
        dfs(rooms, roomsSize, roomsColSize, rooms[current][i], visited);
    }
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize) {
    HashEntry *visited = NULL;

    dfs(rooms, roomsSize, roomsColSize, 0, &visited);

    int count = HASH_COUNT(visited);

    HashEntry *entry = NULL;
    HashEntry *tmp = NULL;

    HASH_ITER(hh, visited, entry, tmp) {
        HASH_DEL(visited, entry);
        free(entry);
    }

    visited = NULL;

    return count == roomsSize;
}

#define QUEUE_SIZE 3000

typedef struct {
    int room;
    UT_hash_handle hh;
} HashEntry;

static void freeAllHashEntries(HashEntry **visited) {
    HashEntry *entry = NULL;
    HashEntry *tmp = NULL;

    HASH_ITER(hh, *visited, entry, tmp) {
        HASH_DEL(*visited, entry);
        free(entry);
    }

    *visited = NULL;
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize) {
    HashEntry *visited = NULL;
    int q[QUEUE_SIZE];
    int front = 0;
    int rear = 1;

    q[0] = 0;

    while (front < rear) {
        int current = q[front++];

        HashEntry *entry = NULL;

        HASH_FIND_INT(visited, &current, entry);

        if (entry == NULL) {
            entry = (HashEntry *)malloc(sizeof(HashEntry));
            if (entry == NULL) {
                freeAllHashEntries(&visited);
                return false;
            }

            entry->room = current;

            HASH_ADD_INT(visited, room, entry);
        }

        for (int i = 0; i < roomsColSize[current]; i++) {
            HASH_FIND_INT(visited, &rooms[current][i], entry);

            if (entry == NULL) {
                q[rear++] = rooms[current][i];
            }
        }
    }

    int count = HASH_COUNT(visited);

    freeAllHashEntries(&visited);

    return count == roomsSize;
}