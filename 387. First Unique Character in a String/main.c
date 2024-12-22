#include <limits.h>
#include <stdio.h>

#define ARRAY_SIZE 26

int firstUniqChar(char *s) {
    int len = strlen(s);
    int count[ARRAY_SIZE] = {0};
    int first[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        first[i] = INT_MAX;
    }

    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';
        count[index]++;
        if (first[index] == INT_MAX) {
            first[index] = i;
        }
    }

    int min = INT_MAX;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (count[i] == 1 && first[i] < min) {
            min = first[i];
        }
    }

    if (min == INT_MAX) {
        return -1;
    }

    return min;
}

#define ARRAY_SIZE 26

int firstUniqChar(char *s) {
    int len = strlen(s);
    int count[ARRAY_SIZE] = {0};

    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}