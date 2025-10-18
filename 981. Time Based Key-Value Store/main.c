#include "uthash.h"
#include <stdbool.h>
#include <stdio.h>

#define TIME_ITEM_MAX_COUNT 100000

typedef struct {
    int timestamp;
    char *value;
} TimeItem;

typedef struct {
    char *key;
    int count;
    TimeItem *item[TIME_ITEM_MAX_COUNT];
    UT_hash_handle hh;
} TimeEntry;

typedef struct {
    TimeEntry *maps;
} TimeMap;

TimeMap *timeMapCreate(void) {
    return (TimeMap *)calloc(1, sizeof(TimeMap));
}

void timeMapSet(TimeMap *obj, char *key, char *value, int timestamp) {
    if (obj == NULL || key == NULL || value == NULL) {
        return;
    }

    TimeEntry *t = NULL;

    HASH_FIND_STR(obj->maps, key, t);
    if (t == NULL) {
        t = (TimeEntry *)calloc(1, sizeof(TimeEntry));
        if (t == NULL) {
            return;
        }

        t->key = strdup(key);
        HASH_ADD_STR(obj->maps, key, t);
    }

    if (t->count >= TIME_ITEM_MAX_COUNT) {
        return;
    }

    t->item[t->count] = malloc(sizeof(TimeItem));
    if (t->item[t->count] == NULL) {
        return;
    }

    t->item[t->count]->timestamp = timestamp;
    t->item[t->count]->value = strdup(value);
    t->count++;
}

char *timeMapGet(TimeMap *obj, char *key, int timestamp) {
    if (obj == NULL || key == NULL) {
        return "";
    }

    TimeEntry *t = NULL;

    HASH_FIND_STR(obj->maps, key, t);
    if (t == NULL) {
        return "";
    }

    int left = 0;
    int right = t->count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (t->item[mid]->timestamp <= timestamp) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (right < 0 || t->item[right] == NULL || t->item[right]->value == NULL) {
        return "";
    }

    return strdup(t->item[right]->value);
}

void timeMapFree(TimeMap *obj) {
    if (obj == NULL) {
        return;
    }

    TimeEntry *t = NULL;
    TimeEntry *temp = NULL;

    HASH_ITER(hh, obj->maps, t, temp) {
        if (t == NULL) {
            continue;
        }

        for (int i = 0; i < t->count; i++) {
            if (t->item[i] == NULL) {
                continue;
            }

            if (t->item[i]->value != NULL) {
                free(t->item[i]->value);
            }

            free(t->item[i]);
            t->item[i] = NULL;
        }

        if (t->key != NULL) {
            free(t->key);
        }

        HASH_DEL(obj->maps, t);
        free(t);
    }

    free(obj);
}

/**
 * Your TimeMap struct will be instantiated and called as such:
 * TimeMap* obj = timeMapCreate();
 * timeMapSet(obj, key, value, timestamp);
 * char* param_2 = timeMapGet(obj, key, timestamp);
 * timeMapFree(obj);
 */

typedef struct _TimeNode {
    int timestamp;
    char *value;
    struct _TimeNode *next;
} TimeNode;

typedef struct {
    char *key;
    TimeNode *head;
    UT_hash_handle hh;
} TimeEntry;

typedef struct {
    TimeEntry *maps;
} TimeMap;

TimeMap *timeMapCreate(void) {
    return (TimeMap *)calloc(1, sizeof(TimeMap));
}

void timeMapSet(TimeMap *obj, char *key, char *value, int timestamp) {
    if (obj == NULL || key == NULL || value == NULL) {
        return;
    }

    TimeEntry *t = NULL;

    HASH_FIND_STR(obj->maps, key, t);
    if (t == NULL) {
        t = (TimeEntry *)calloc(1, sizeof(TimeEntry));
        if (t == NULL) {
            return;
        }

        t->key = strdup(key);
        HASH_ADD_STR(obj->maps, key, t);
    }

    TimeNode *node = (TimeNode *)calloc(1, sizeof(TimeNode));
    if (node == NULL) {
        return;
    }

    node->timestamp = timestamp;
    node->value = strdup(value);
    node->next = t->head;
    t->head = node;
}

char *timeMapGet(TimeMap *obj, char *key, int timestamp) {
    if (obj == NULL || key == NULL) {
        return "";
    }

    TimeEntry *t = NULL;

    HASH_FIND_STR(obj->maps, key, t);
    if (t == NULL) {
        return "";
    }

    TimeNode *node = t->head;

    while (node != NULL) {
        if (node->timestamp <= timestamp) {
            return node->value;
        }

        node = node->next;
    }

    return "";
}

void timeMapFree(TimeMap *obj) {
    if (obj == NULL) {
        return;
    }

    TimeEntry *t = NULL;
    TimeEntry *temp = NULL;

    HASH_ITER(hh, obj->maps, t, temp) {
        if (t == NULL) {
            continue;
        }

        TimeNode *node = t->head;

        while (node != NULL) {
            TimeNode *current = node;
            node = node->next;

            free(current);
        }

        free(t);
    }

    free(obj);
}

/**
 * Your TimeMap struct will be instantiated and called as such:
 * TimeMap* obj = timeMapCreate();
 * timeMapSet(obj, key, value, timestamp);
 * char* param_2 = timeMapGet(obj, key, timestamp);
 * timeMapFree(obj);
 */