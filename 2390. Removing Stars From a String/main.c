#include <stdbool.h>
#include <stdio.h>

char *removeStars(char *s) {
    size_t len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    int count = 0;

    for (size_t i = 0; i < len; i++) {
        if (s[i] == '*') {
            count--;
        } else {
            result[count++] = s[i];
        }
    }

    result[count] = '\0';

    return result;
}