#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 128

typedef struct {
    char *str;
    char c;
} ReverseMapping;

static int findWordIndex(ReverseMapping *reverseMapping, int count, char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(reverseMapping[i].str, word) == 0) {
            return i;
        }
    }

    return -1;
}

bool wordPattern(char *pattern, char *s) {
    size_t size = strlen(pattern);
    char *directMapping[ARRAY_SIZE];
    memset(directMapping, 0, ARRAY_SIZE * sizeof(char *));
    size_t len = (size > ARRAY_SIZE) ? size : ARRAY_SIZE;
    ReverseMapping reverseMapping[len];
    int count = 0;
    char *saveptr = NULL;
    char *word = strtok_r(s, " ", &saveptr);

    for (size_t i = 0; i < size; i++) {
        if (word == NULL) {
            return false;
        }

        int index = findWordIndex(reverseMapping, count, word);
        if (directMapping[pattern[i]] == NULL && index == -1) {
            directMapping[pattern[i]] = word;
            reverseMapping[count].str = word;
            reverseMapping[count].c = pattern[i];
            count++;
        } else if ((directMapping[pattern[i]] != NULL && strcmp(directMapping[pattern[i]], word) != 0) ||
                   (index >= 0 && reverseMapping[index].c != pattern[i])) {
            return false;
        }

        word = strtok_r(NULL, " ", &saveptr);
    }

    if (word != NULL) {
        return false;
    }

    return true;
}

#define ARRAY_SIZE 26

bool wordPattern(char *pattern, char *s) {
    size_t patternLen = strlen(pattern);
    char *hashmap[ARRAY_SIZE] = {NULL};
    size_t idx = 0;
    char *saveptr = NULL;
    char *word = strtok_r(s, " ", &saveptr);

    while (word != NULL) {
        if (idx >= patternLen) {
            return false;
        }

        size_t index = pattern[idx] - 'a';
        if (hashmap[index] == NULL) {
            for (size_t i = 0; i < ARRAY_SIZE; i++) {
                if (hashmap[i] != NULL && strcmp(hashmap[i], word) == 0) {
                    return false;
                }
            }

            hashmap[index] = word;
        } else {
            if (strcmp(hashmap[index], word) != 0) {
                return false;
            }
        }

        word = strtok_r(NULL, " ", &saveptr);
        idx++;
    }

    return idx == patternLen;
}