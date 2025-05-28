#include <stdbool.h>
#include <stdio.h>
#include <uthash.h>

static bool isValid(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (len1 != len2) {
        return false;
    }

    size_t diff = 0;

    for (size_t i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) {
            diff++;
        }
    }

    return diff == 1;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize) {
    size_t wordLen = strlen(beginWord);
    bool visited[wordListSize];
    char *q[wordListSize + 1];
    int steps[wordListSize + 1];
    size_t front = 0;
    size_t rear = 0;
    bool matched = false;

    q[rear] = beginWord;
    steps[rear] = 1;
    rear++;

    for (int i = 0; i < wordListSize; i++) {
        visited[i] = false;
        if (strcmp(endWord, wordList[i]) == 0) {
            matched = true;
        }
    }

    if (!matched) {
        return 0;
    }

    while (front < rear) {
        char *current = q[front];
        int step = steps[front];
        front++;

        if (strcmp(current, endWord) == 0) {
            return step;
        }

        for (int i = 0; i < wordListSize; i++) {
            if (!visited[i] && isValid(current, wordList[i])) {
                q[rear] = wordList[i];
                steps[rear] = step + 1;
                rear++;
                visited[i] = true;
            }
        }
    }

    return 0;
}

#define ALPHABET_SIZE 26

typedef struct {
    char *key;
    UT_hash_handle hh;
} HashEntry;

static void freeHashEntries(HashEntry **maps) {
    HashEntry *entry = NULL;
    HashEntry *tmp = NULL;

    HASH_ITER(hh, *maps, entry, tmp) {
        HASH_DEL(*maps, entry);
        free(entry);
    }

    *maps = NULL;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize) {
    HashEntry *maps = NULL;
    HashEntry *entry = NULL;

    for (int i = 0; i < wordListSize; i++) {
        entry = (HashEntry *)malloc(sizeof(HashEntry));
        entry->key = wordList[i];
        HASH_ADD_STR(maps, key, entry);
    }

    size_t wordLen = strlen(beginWord);
    char *q[wordListSize + 1];
    int steps[wordListSize + 1];
    size_t front = 0;
    size_t rear = 0;

    q[rear] = beginWord;
    steps[rear] = 1;
    rear++;

    while (front < rear) {
        char *current = q[front];
        int step = steps[front];
        front++;

        if (strcmp(current, endWord) == 0) {
            freeHashEntries(&maps);
            return step;
        }

        for (int i = 0; i < wordLen; i++) {
            char original = current[i];

            for (int j = 0; j < ALPHABET_SIZE; j++) {
                current[i] = 'a' + j;

                if (current[i] == original) {
                    continue;
                }

                HASH_FIND_STR(maps, current, entry);
                if (entry != NULL) {
                    q[rear] = entry->key;
                    steps[rear] = step + 1;
                    rear++;
                    HASH_DEL(maps, entry);
                }
            }

            current[i] = original;
        }
    }

    freeHashEntries(&maps);
    return 0;
}