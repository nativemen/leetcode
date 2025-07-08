#include "uthash.h"
#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 1002

typedef struct {
    int array[ARRAY_SIZE];
    int smallest;
} SmallestInfiniteSet;

SmallestInfiniteSet *smallestInfiniteSetCreate(void) {
    SmallestInfiniteSet *set = (SmallestInfiniteSet *)malloc(sizeof(SmallestInfiniteSet));
    if (set == NULL) {
        return NULL;
    }

    set->smallest = 1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        set->array[i] = i;
    }

    return set;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj) {
    if (obj == NULL) {
        return -1;
    }

    int smallest = obj->smallest;
    obj->array[smallest] = 0;

    for (int i = smallest + 1; i < ARRAY_SIZE; i++) {
        if (obj->array[i] != 0) {
            obj->smallest = i;
            break;
        }
    }

    return smallest;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num) {
    if (obj == NULL) {
        return;
    }

    obj->array[num] = num;

    if (obj->smallest > num) {
        obj->smallest = num;
    }
}

void smallestInfiniteSetFree(SmallestInfiniteSet *obj) {
    if (obj == NULL) {
        return;
    }

    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 * smallestInfiniteSetAddBack(obj, num);
 * smallestInfiniteSetFree(obj);
 */

typedef struct {
    int val;
    UT_hash_handle hh;
} HashEntry;

typedef struct {
    HashEntry *entry;
    int smallest;
} SmallestInfiniteSet;

SmallestInfiniteSet *smallestInfiniteSetCreate(void) {
    SmallestInfiniteSet *set = (SmallestInfiniteSet *)malloc(sizeof(SmallestInfiniteSet));
    if (set == NULL) {
        return NULL;
    }

    set->entry = NULL;
    set->smallest = 1;

    return set;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj) {
    if (obj == NULL) {
        return -1;
    }

    if (obj->entry == NULL) {
        return obj->smallest++;
    }

    HashEntry *entry = obj->entry;
    int smallest = entry->val;

    HASH_DEL(obj->entry, entry);
    free(entry);

    return smallest;
}

static int compare(void *a, void *b) {
    HashEntry *entry1 = (HashEntry *)a;
    HashEntry *entry2 = (HashEntry *)b;

    return entry1->val - entry2->val;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num) {
    if (obj == NULL) {
        return;
    }

    if (num >= obj->smallest) {
        return;
    }

    HashEntry *entry = NULL;
    HASH_FIND_INT(obj->entry, &num, entry);

    if (entry != NULL) {
        return;
    }

    entry = (HashEntry *)malloc(sizeof(HashEntry));
    if (entry == NULL) {
        return;
    }

    entry->val = num;

    HASH_ADD_INORDER(hh, obj->entry, val, sizeof(int), entry, compare);
}

void smallestInfiniteSetFree(SmallestInfiniteSet *obj) {
    if (obj == NULL) {
        return;
    }

    HashEntry *entry = NULL;
    HashEntry *tmp = NULL;

    HASH_ITER(hh, obj->entry, entry, tmp) {
        HASH_DEL(obj->entry, entry);
        free(entry);
    }

    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 * smallestInfiniteSetAddBack(obj, num);
 * smallestInfiniteSetFree(obj);
 */