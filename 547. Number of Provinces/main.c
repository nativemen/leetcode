#include <stdbool.h>
#include <stdio.h>

static void init(int *parent, int size) {
    for (int i = 0; i < size; i++) {
        parent[i] = i;
    }
}

static int find(int *parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }

    return parent[x];
}

static void unionSet(int *parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize) {
    int parent[isConnectedSize];

    init(parent, isConnectedSize);

    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = 0; j < isConnectedColSize[i]; j++) {
            if (isConnected[i][j] == 1) {
                unionSet(parent, i, j);
            }
        }
    }

    int count = 0;

    for (int i = 0; i < isConnectedSize; i++) {
        if (parent[i] == i) {
            count++;
        }
    }

    return count;
}

static void dfs(int **isConnected, int isConnectedSize, int *isConnectedColSize, int *visited, int current) {
    visited[current] = 1;

    for (int i = 0; i < isConnectedColSize[current]; i++) {
        if (isConnected[current][i] == 1 && visited[i] == 0) {
            dfs(isConnected, isConnectedSize, isConnectedColSize, visited, i);
        }
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize) {
    int visited[isConnectedSize];

    memset(visited, 0, isConnectedSize * sizeof(int));

    int count = 0;

    for (int i = 0; i < isConnectedSize; i++) {
        if (visited[i] == 0) {
            dfs(isConnected, isConnectedSize, isConnectedColSize, visited, i);

            count++;
        }
    }

    return count;
}