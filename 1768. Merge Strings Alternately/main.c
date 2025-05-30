#include <stdio.h>

char *mergeAlternately(char *word1, char *word2) {
    size_t len1 = strlen(word1);
    size_t len2 = strlen(word2);

    char *result = (char *)calloc(len1 + len2 + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    int index = 0;

    while (index < len1 || index < len2) {
        if (index < len1) {
            result[count++] = word1[index];
        }

        if (index < len2) {
            result[count++] = word2[index];
        }

        index++;
    }

    return result;
}

char *mergeAlternately(char *word1, char *word2) {
    size_t len1 = strlen(word1);
    size_t len2 = strlen(word2);

    char *result = (char *)calloc(len1 + len2 + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    int i = 0;
    int j = 0;

    while (i < len1 || j < len2) {
        if (i < len1) {
            result[count++] = word1[i++];
        }

        if (j < len2) {
            result[count++] = word2[j++];
        }
    }

    return result;
}