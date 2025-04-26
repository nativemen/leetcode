#include <stdio.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

#define ARRAY_SIZE 101

static struct Node *dfs(struct Node *s, struct Node **visited) {
    if (visited[s->val] != NULL) {
        return visited[s->val];
    }

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    visited[s->val] = node;
    node->val = s->val;
    node->numNeighbors = s->numNeighbors;

    if (node->numNeighbors == 0) {
        node->neighbors = NULL;
        return node;
    }

    node->neighbors = (struct Node **)calloc(node->numNeighbors, sizeof(struct Node *));
    for (int i = 0; i < node->numNeighbors; i++) {
        node->neighbors[i] = dfs(s->neighbors[i], visited);
    }

    return node;
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) {
        return NULL;
    }

    struct Node *visited[ARRAY_SIZE] = {NULL};
    return dfs(s, visited);
}