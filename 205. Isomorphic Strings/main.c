#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 128

bool isIsomorphic(char *s, char *t) {
    char directMapping[ARRAY_SIZE] = {0};
    char reverseMapping[ARRAY_SIZE] = {0};

    for (size_t i = 0; i < strlen(s); i++) {
        if ((directMapping[(unsigned int)s[i]] != 0 && directMapping[(unsigned int)s[i]] != t[i]) ||
            (reverseMapping[(unsigned int)t[i]] != 0 && reverseMapping[(unsigned int)t[i]] != s[i])) {
            return false;
        }

        directMapping[(unsigned int)s[i]] = t[i];
        reverseMapping[(unsigned int)t[i]] = s[i];
    }

    return true;
}

#define ARRAY_SIZE 128

bool isIsomorphic(char *s, char *t) {
    char directMapping[ARRAY_SIZE] = {0};
    char reverseMapping[ARRAY_SIZE] = {0};

    for (size_t i = 0; s[i] != '\0'; i++) {
        if (directMapping[s[i]] == 0 && reverseMapping[t[i]] == 0) {
            directMapping[s[i]] = t[i];
            reverseMapping[t[i]] = s[i];
        }

        if (directMapping[s[i]] != t[i] || reverseMapping[t[i]] != s[i]) {
            return false;
        }
    }

    return true;
}