#include <stdbool.h>
#include <stdio.h>
#include <uthash.h>

typedef struct _HashEntry {
    int id;
    UT_hash_handle hh;
} HashEntry;

typedef struct {
    HashEntry *set;
} RandomizedSet;

RandomizedSet *randomizedSetCreate() {
    return (RandomizedSet *)calloc(1, sizeof(RandomizedSet));
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    HashEntry *entry;

    HASH_FIND_INT(obj->set, &val, entry);
    if (entry == NULL) {
        entry = (HashEntry *)calloc(1, sizeof(HashEntry));
        entry->id = val;
        HASH_ADD_INT(obj->set, id, entry);
        return true;
    }

    return false;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    HashEntry *entry;

    HASH_FIND_INT(obj->set, &val, entry);
    if (entry != NULL) {
        HASH_DEL(obj->set, entry);
        free(entry);
        return true;
    }

    return false;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    int count = HASH_COUNT(obj->set);
    int index = rand() % count;
    HashEntry *cur = NULL;
    HashEntry *tmp = NULL;

    HASH_ITER(hh, obj->set, cur, tmp) {
        if (index == 0) {
            break;
        }
        index--;
    }

    return cur->id;
}

void randomizedSetFree(RandomizedSet *obj) {
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 * bool param_2 = randomizedSetRemove(obj, val);
 * int param_3 = randomizedSetGetRandom(obj);
 * randomizedSetFree(obj);
 */
