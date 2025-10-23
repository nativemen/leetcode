#include "uthash.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int id;
    int val;
    UT_hash_handle hh;
} SnapEntry;

typedef struct {
    SnapEntry **entry;
    int size;
    int snap_id;
} SnapshotArray;

SnapshotArray *snapshotArrayCreate(int length) {
    SnapshotArray *array = (SnapshotArray *)calloc(1, sizeof(SnapshotArray));
    if (array == NULL) {
        return NULL;
    }

    array->entry = (SnapEntry **)calloc(length, sizeof(SnapEntry *));
    if (array->entry == NULL) {
        free(array);
        return NULL;
    }

    array->size = length;
    array->snap_id = 0;

    return array;
}

void snapshotArraySet(SnapshotArray *obj, int index, int val) {
    if (obj == NULL || index < 0 || index >= obj->size) {
        return;
    }

    SnapEntry *s = NULL;

    HASH_FIND_INT(obj->entry[index], &obj->snap_id, s);

    if (s == NULL) {
        s = (SnapEntry *)calloc(1, sizeof(SnapEntry));
        if (s == NULL) {
            return;
        }

        s->id = obj->snap_id;
        s->val = val;

        HASH_ADD_INT(obj->entry[index], id, s);
    } else {
        s->val = val;
    }
}

int snapshotArraySnap(SnapshotArray *obj) {
    if (obj == NULL) {
        return -1;
    }

    return obj->snap_id++;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id) {
    if (obj == NULL || index < 0 || index >= obj->size || snap_id < 0 || snap_id > obj->snap_id) {
        return -1;
    }

    SnapEntry *s = NULL;

    for (int i = snap_id; i >= 0; i--) {
        HASH_FIND_INT(obj->entry[index], &i, s);
        if (s != NULL) {
            return s->val;
        }
    }

    return 0;
}

void snapshotArrayFree(SnapshotArray *obj) {
    if (obj == NULL) {
        return;
    }

    SnapEntry *s = NULL;
    SnapEntry *temp = NULL;

    for (int i = 0; i < obj->size; i++) {
        HASH_ITER(hh, obj->entry[i], s, temp) {
            if (s != NULL) {
                HASH_DEL(obj->entry[i], s);
                free(s);
            }
        }
    }

    free(obj->entry);
    free(obj);
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);
 * int param_2 = snapshotArraySnap(obj);
 * int param_3 = snapshotArrayGet(obj, index, snap_id);
 * snapshotArrayFree(obj);
 */

typedef struct {
    int id;
    int val;
} SnapItem;

typedef struct {
    SnapItem *item;
    int count;
    int size;
} SnapEntry;

typedef struct {
    SnapEntry *entry;
    int size;
    int snap_id;
} SnapshotArray;

SnapshotArray *snapshotArrayCreate(int length) {
    SnapshotArray *array = (SnapshotArray *)calloc(1, sizeof(SnapshotArray));
    if (array == NULL) {
        return NULL;
    }

    array->entry = (SnapEntry *)calloc(length, sizeof(SnapEntry));
    if (array->entry == NULL) {
        free(array);
        return NULL;
    }

    array->size = length;
    array->snap_id = 0;

    return array;
}

void snapshotArraySet(SnapshotArray *obj, int index, int val) {
    if (obj == NULL || index < 0 || index >= obj->size) {
        return;
    }

    if (obj->entry[index].size <= obj->entry[index].count) {
        obj->entry[index].size = (obj->entry[index].size == 0) ? 2 : obj->entry[index].size * 2;
        obj->entry[index].item = (SnapItem *)realloc(obj->entry[index].item, obj->entry[index].size * sizeof(SnapItem));
    }

    obj->entry[index].item[obj->entry[index].count].id = obj->snap_id;
    obj->entry[index].item[obj->entry[index].count].val = val;
    obj->entry[index].count++;
}

int snapshotArraySnap(SnapshotArray *obj) {
    if (obj == NULL) {
        return -1;
    }

    return obj->snap_id++;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id) {
    if (obj == NULL || index < 0 || index >= obj->size || snap_id < 0 || snap_id > obj->snap_id) {
        return -1;
    }

    int left = 0;
    int right = obj->entry[index].count - 1;
    int val = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (obj->entry[index].item[mid].id <= snap_id) {
            val = obj->entry[index].item[mid].val;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return val;
}

void snapshotArrayFree(SnapshotArray *obj) {
    if (obj == NULL) {
        return;
    }

    for (int i = 0; i < obj->size; i++) {
        if (obj->entry[i].item != NULL) {
            free(obj->entry[i].item);
            obj->entry[i].item = NULL;
        }
    }

    if (obj->entry != NULL) {
        free(obj->entry);
        obj->entry = NULL;
    }

    free(obj);
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);
 * int param_2 = snapshotArraySnap(obj);
 * int param_3 = snapshotArrayGet(obj, index, snap_id);
 * snapshotArrayFree(obj);
 */