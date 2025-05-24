#include "uthash.h"
#include <stdio.h>

#define VALUE_SIZE 20
#define QUERY_SIZE 20

typedef struct {
    char *b;
    double val;
} Value;

typedef struct {
    char *a;
    Value value[VALUE_SIZE];
    int count;
    UT_hash_handle hh;
} HashEntry;

static HashEntry *findEntry(HashEntry *users, char *a) {
    HashEntry *s = NULL;

    HASH_FIND_STR(users, a, s);

    return s;
}

static void addEntry(HashEntry **users, char *a, char *b, double value) {
    HashEntry *s = findEntry(*users, a);
    if (s == NULL) {
        s = (HashEntry *)calloc(1, sizeof(HashEntry));
        if (s == NULL) {
            return;
        }

        s->a = strdup(a);
        s->count = 0;
        HASH_ADD_STR(*users, a, s);
    }

    s->value[s->count].b = strdup(b);
    s->value[s->count].val = value;
    s->count++;
}

static void freeAllEntries(HashEntry **users) {
    HashEntry *s = NULL;
    HashEntry *tmp = NULL;

    HASH_ITER(hh, *users, s, tmp) {
        HASH_DEL(*users, s);
        for (int i = 0; i < s->count; i++) {
            free(s->value[i].b);
        }
        free(s->a);
        free(s);
    }

    *users = NULL;
}

typedef struct {
    char *a;
    UT_hash_handle hh;
} HashSet;

static HashSet *findSet(HashSet *set, char *a) {
    HashSet *s = NULL;

    HASH_FIND_STR(set, a, s);

    return s;
}

static void addSet(HashSet **set, char *a) {
    if (findSet(*set, a) != NULL) {
        return;
    }

    HashSet *s = (HashSet *)malloc(sizeof(HashSet));
    if (s == NULL) {
        return;
    }

    s->a = strdup(a);
    HASH_ADD_STR(*set, a, s);
}

static void delSet(HashSet **set, char *a) {
    HashSet *s = findSet(*set, a);
    if (s != NULL) {
        HASH_DEL(*set, s);
        free(s->a);
        free(s);
        return;
    }
}

static void freeAllSet(HashSet **set) {
    HashSet *s = NULL;
    HashSet *tmp = NULL;

    HASH_ITER(hh, *set, s, tmp) {
        HASH_DEL(*set, s);
        free(s->a);
        free(s);
    }

    *set = NULL;
}

static void dfs(HashEntry **users, HashSet **visited, char *src, char *dest, double value, double *answer) {
    addSet(visited, src);

    if (strcmp(src, dest) == 0) {
        *answer = value;
        return;
    }

    HashEntry *s = findEntry(*users, src);
    if (s != NULL) {
        for (int i = 0; i < s->count; i++) {
            if (findSet(*visited, s->value[i].b) == NULL) {
                dfs(users, visited, s->value[i].b, dest, value * s->value[i].val, answer);
            }
        }
    }

    delSet(visited, src);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double *calcEquation(char ***equations,
                     int equationsSize,
                     int *equationsColSize,
                     double *values,
                     int valuesSize,
                     char ***queries,
                     int queriesSize,
                     int *queriesColSize,
                     int *returnSize) {
    HashEntry *users = NULL;

    for (int i = 0; i < equationsSize; i++) {
        addEntry(&users, equations[i][0], equations[i][1], values[i]);
        addEntry(&users, equations[i][1], equations[i][0], 1.0 / values[i]);
    }

    *returnSize = 0;
    double *result = (double *)malloc(QUERY_SIZE * sizeof(double));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;

    for (int i = 0; i < queriesSize; i++) {
        if (findEntry(users, queries[i][0]) == NULL && findEntry(users, queries[i][1]) == NULL) {
            result[count++] = -1.0;
            continue;
        }

        HashSet *visited = NULL;
        double answer = -1.0;

        dfs(&users, &visited, queries[i][0], queries[i][1], 1.0, &answer);

        result[count++] = answer;
        freeAllSet(&visited);
    }

    *returnSize = count;

    return result;
}