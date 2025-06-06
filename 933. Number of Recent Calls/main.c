#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 3001

typedef struct {
    int request[ARRAY_SIZE];
    int current;
} RecentCounter;

RecentCounter *recentCounterCreate() {
    return (RecentCounter *)calloc(1, sizeof(RecentCounter));
}

int recentCounterPing(RecentCounter *obj, int t) {
    if (obj == NULL) {
        return 0;
    }

    if (obj->current + ARRAY_SIZE <= t) {
        memset(obj->request, 0, ARRAY_SIZE * sizeof(int));
    } else {
        for (int i = obj->current + 1; i < t; i++) {
            obj->request[i % ARRAY_SIZE] = 0;
        }
    }

    obj->request[t % ARRAY_SIZE] = 1;
    obj->current = t;

    int count = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (obj->request[i] == 1) {
            count++;
        }
    }

    return count;
}

void recentCounterFree(RecentCounter *obj) {
    if (obj != NULL) {
        free(obj);
    }
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */

#define ARRAY_SIZE 10001
#define TIME_OFFSET 3000

typedef struct {
    int time[ARRAY_SIZE];
    int head;
    int tail;
} RecentCounter;

RecentCounter *recentCounterCreate() {
    return (RecentCounter *)calloc(1, sizeof(RecentCounter));
}

int recentCounterPing(RecentCounter *obj, int t) {
    if (obj == NULL) {
        return 0;
    }

    obj->time[obj->tail++] = t;

    while (obj->time[obj->head] + TIME_OFFSET < t) {
        obj->head++;
    }

    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter *obj) {
    if (obj != NULL) {
        free(obj);
    }
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */