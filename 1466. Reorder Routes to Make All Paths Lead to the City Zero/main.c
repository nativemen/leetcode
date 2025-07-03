#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 50000

typedef struct {
    int array[ARRAY_SIZE];
    int size;
} Map;

static void dfs(Map *maps, int *visited, int n, int current, int *count) {
    visited[current] = 1;

    for (int i = 0; i < maps[current].size; i++) {
        if (visited[abs(maps[current].array[i])] == 0) {
            if (maps[current].array[i] > 0) {
                *count += 1;
            }

            dfs(maps, visited, n, abs(maps[current].array[i]), count);
        }
    }
}

int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize) {
    int *visited = (int *)calloc(n, sizeof(int));
    if (visited == NULL) {
        return -1;
    }

    Map *maps = (Map *)calloc(n, sizeof(Map));
    if (maps == NULL) {
        free(visited);
        return -1;
    }

    for (int i = 0; i < connectionsSize; i++) {
        maps[connections[i][0]].array[maps[connections[i][0]].size++] = connections[i][1];
        maps[connections[i][1]].array[maps[connections[i][1]].size++] = -connections[i][0];
    }

    int count = 0;

    dfs(maps, visited, n, 0, &count);
    free(maps);
    free(visited);

    return count;
}