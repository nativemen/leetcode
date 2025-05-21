#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 2000

typedef struct {
    int array[ARRAY_SIZE];
    int count;
} Adj;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize) {
    *returnSize = 0;
    int *result = (int *)malloc(numCourses * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    Adj adj[numCourses];
    memset(adj, 0, numCourses * sizeof(Adj));
    int indegree[numCourses];
    memset(indegree, 0, numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        adj[prerequisites[i][0]].array[adj[prerequisites[i][0]].count++] = prerequisites[i][1];
        indegree[prerequisites[i][1]]++;
    }

    int q[numCourses * 2];
    int head = 0;
    int tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q[tail++] = i;
        }
    }

    int count = numCourses - 1;

    while (head != tail) {
        int course = q[head++];
        result[count--] = course;

        for (int i = 0; i < adj[course].count; i++) {
            int neighbor = adj[course].array[i];
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q[tail++] = neighbor;
            }
        }
    }

    if (count != -1) {
        free(result);
        return NULL;
    }

    *returnSize = numCourses;

    return result;
}

#define ARRAY_SIZE 2000

typedef struct {
    int array[ARRAY_SIZE];
    int count;
} Adj;

static bool hasCycle(Adj *adj, int *visited, int *result, int *count, int index) {
    if (visited[index] == 1) {
        return true;
    }

    if (visited[index] == 2) {
        return false;
    }

    visited[index] = 1;

    for (int i = 0; i < adj[index].count; i++) {
        if (hasCycle(adj, visited, result, count, adj[index].array[i])) {
            return true;
        }
    }

    visited[index] = 2;
    result[(*count)++] = index;

    return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize) {
    Adj adj[numCourses];
    memset(adj, 0, numCourses * sizeof(Adj));
    int visited[numCourses];
    memset(visited, 0, numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        adj[prerequisites[i][0]].array[adj[prerequisites[i][0]].count++] = prerequisites[i][1];
    }

    *returnSize = 0;
    int *result = (int *)malloc(numCourses * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < numCourses; i++) {
        if (hasCycle(adj, visited, result, &count, i)) {
            free(result);
            return NULL;
        }
    }

    *returnSize = numCourses;

    return result;
}