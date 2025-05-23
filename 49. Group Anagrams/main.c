#include <uthash.h>

#define ARRAY_SIZE 10000

typedef struct {
    char *id;
    char *strs[ARRAY_SIZE];
    int count;
    UT_hash_handle hh;
} HashEntry;

static HashEntry *findUser(HashEntry *users, const char *id) {
    HashEntry *user = NULL;

    HASH_FIND_STR(users, id, user);

    return user;
}

static void addUser(HashEntry **users, const char *id, const char *str) {
    HashEntry *user = findUser(*users, id);

    if (user != NULL) {
        user->strs[user->count++] = strdup(str);
        return;
    }

    user = (HashEntry *)malloc(sizeof(HashEntry));
    user->id = strdup(id);
    user->strs[0] = strdup(str);
    user->count = 1;
    HASH_ADD_STR(*users, id, user);
}

static int compare(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    char ***result = (char ***)calloc(strsSize, sizeof(char **));
    *returnColumnSizes = (int *)calloc(strsSize, sizeof(int));
    HashEntry *users = NULL;

    for (size_t i = 0; i < strsSize; i++) {
        char *id = strdup(strs[i]);
        qsort(id, strlen(id), sizeof(char), compare);
        addUser(&users, id, strs[i]);
        free(id);
    }

    HashEntry *user = NULL;
    HashEntry *tmp = NULL;
    int index = 0;

    HASH_ITER(hh, users, user, tmp) {
        (*returnColumnSizes)[index] = user->count;
        result[index] = (char **)malloc(user->count * sizeof(char *));
        for (size_t i = 0; i < user->count; i++) {
            result[index][i] = user->strs[i];
        }
        HASH_DEL(users, user);
        free(user->id);
        free(user);
        index++;
    }

    *returnSize = index;

    return result;
}