#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 2000

typedef struct {
    int array[ARRAY_SIZE];
    int count;
} Adj;

static bool hasCycle(Adj *adj, int *visited, int index) {
    if (visited[index] == 1) {
        return true;
    }

    if (visited[index] == 2) {
        return false;
    }

    visited[index] = 1;

    for (int i = 0; i < adj[index].count; i++) {
        if (hasCycle(adj, visited, adj[index].array[i])) {
            return true;
        }
    }

    visited[index] = 2;

    return false;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize) {
    if (numCourses == 1 || prerequisites == NULL || prerequisitesSize <= 1) {
        return true;
    }

    Adj adj[numCourses];
    memset(adj, 0, numCourses * sizeof(Adj));
    int visited[numCourses];
    memset(visited, 0, numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        adj[prerequisites[i][0]].array[adj[prerequisites[i][0]].count++] = prerequisites[i][1];
    }

    for (int i = 0; i < numCourses; i++) {
        if (hasCycle(adj, visited, i)) {
            return false;
        }
    }

    return true;
}