#include "uthash.h"
#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 256

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char *s) {
    int size = strlen(s);
    int result = 0;
    int left = 0;
    int count[ARRAY_SIZE] = {0};

    for (int right = 0; right < size; right++) {
        count[(size_t)s[right]]++;
        while (count[(size_t)s[right]] > 1) {
            count[(size_t)s[left++]]--;
        }
        result = max(result, right - left + 1);
    }

    return result;
}

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char *s) {
    int size = strlen(s);
    int result = 0;
    int left = 0;

    for (int right = 0; right < size; right++) {
        for (int start = left; start < right; start++) {
            if (s[start] == s[right]) {
                left = start + 1;
                break;
            }
        }
        result = max(result, right - left + 1);
    }

    return result;
}

struct hash_entry {
    int id;
    int index;
    UT_hash_handle hh;
};

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char *s) {
    int size = strlen(s);
    int result = 0;
    int left = 0;
    struct hash_entry *users = NULL;

    for (int right = 0; right < size; right++) {
        struct hash_entry *entry = NULL;
        int id = (int)s[right];
        HASH_FIND_INT(users, &id, entry);
        if (entry != NULL) {
            if (entry->index >= left) {
                left = entry->index + 1;
            }
            entry->index = right;
        } else {
            entry = (struct hash_entry *)malloc(sizeof(struct hash_entry));
            entry->id = (int)s[right];
            entry->index = right;
            HASH_ADD_INT(users, id, entry);
        }

        result = max(result, right - left + 1);
    }

    struct hash_entry *current = NULL;
    struct hash_entry *tmp = NULL;

    HASH_ITER(hh, users, current, tmp) {
        HASH_DEL(users, current);
        free(current);
    }

    return result;
}

struct hash_entry {
    int id;
    UT_hash_handle hh;
};

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char *s) {
    int size = strlen(s);
    int result = 0;
    int left = 0;
    struct hash_entry *users = NULL;

    for (int right = 0; right < size; right++) {
        struct hash_entry *entry = NULL;
        int id = (int)s[right];
        while (true) {
            HASH_FIND_INT(users, &id, entry);
            if (entry == NULL) {
                break;
            }
            int find = (int)s[left];
            HASH_FIND_INT(users, &find, entry);
            if (entry != NULL) {
                HASH_DEL(users, entry);
                free(entry);
                left++;
            }
        }

        entry = (struct hash_entry *)malloc(sizeof(struct hash_entry));
        entry->id = (int)s[right];
        HASH_ADD_INT(users, id, entry);

        result = max(result, right - left + 1);
    }

    struct hash_entry *current = NULL;
    struct hash_entry *tmp = NULL;

    HASH_ITER(hh, users, current, tmp) {
        HASH_DEL(users, current);
        free(current);
    }

    return result;
}