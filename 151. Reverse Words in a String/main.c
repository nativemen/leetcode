#include <stdio.h>

char *reverseWords(char *s) {
    size_t size = strlen(s);
    char **stack = (char **)calloc(size, sizeof(char *));
    if (stack == NULL) {
        return NULL;
    }

    int count = 0;
    char *saveptr = NULL;
    char *token = strtok_r(s, " ", &saveptr);
    while (token != NULL) {
        stack[count++] = token;
        token = strtok_r(NULL, " ", &saveptr);
    }

    char *result = (char *)malloc((size + 1) * sizeof(char));
    if (result == NULL) {
        free(stack);
        return NULL;
    }

    result[0] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        strcat(result, stack[i]);
        if (i > 0) {
            strcat(result, " ");
        }
    }

    free(stack);
    return result;
}

char *reverseWords(char *s) {
    size_t size = strlen(s);
    char *result = (char *)malloc((size + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    int offset = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            count++;
            if (i == 0 || s[i - 1] == ' ') {
                memcpy(result + offset, s + i, count * sizeof(char));
                offset += count;
                result[offset] = ' ';
                offset++;
                count = 0;
            }
        }
    }

    result[offset - 1] = '\0';
    return result;
}