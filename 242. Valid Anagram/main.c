#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 256

bool isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[ARRAY_SIZE] = {0};

    for (int i = 0; i < strlen(s); i++) {
        count[s[i]]++;
        count[t[i]]--;
    }

    for (int i = (int)'a'; i <= (int)'z'; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

#define ARRAY_SIZE 26

bool isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[ARRAY_SIZE] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

static int compare(const void *a, const void *b) {
    return (int)(*(char *)a - *(char *)b);
}

bool isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);

    if (strcmp(s, t) != 0) {
        return false;
    }

    return true;
}