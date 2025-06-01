#include <stdbool.h>
#include <stdio.h>

int compress(char *chars, int charsSize) {
    char *s = (char *)malloc((charsSize + 1) * sizeof(char));
    if (s == NULL) {
        return 0;
    }

    int count = 0;
    int len = 0;

    for (int i = 0; i < charsSize; i++) {
        if (i == 0 || chars[i - 1] == chars[i]) {
            count++;
        }

        if (i + 1 == charsSize || chars[i] != chars[i + 1]) {
            s[len++] = chars[i];
            if (count > 1) {
                sprintf(s + len, "%d", count);
                len = strlen(s);
            }
            count = 1;
        }
    }

    memcpy(chars, s, len);
    free(s);

    return len;
}

#define BUFFER_SIZE 10

int compress(char *chars, int charsSize) {
    int count = 0;
    int len = 0;
    char prev = '\0';

    for (int i = 0; i < charsSize; i++) {
        if (i == 0 || prev == chars[i]) {
            count++;
        }

        prev = chars[i];

        if (i + 1 == charsSize || chars[i] != chars[i + 1]) {
            chars[len++] = chars[i];
            if (count > 1) {
                char buffer[BUFFER_SIZE];
                int size = sprintf(buffer, "%d", count);
                for (int i = 0; i < size; i++) {
                    chars[len++] = buffer[i];
                }
            }
            count = 1;
        }
    }

    return len;
}

#define BUFFER_SIZE 10

int compress(char *chars, int charsSize) {
    int count = 1;
    int len = 0;
    char current = chars[0];

    for (int i = 0; i < charsSize; i++) {
        if (i + 1 == charsSize || chars[i] != chars[i + 1]) {
            chars[len++] = current;
            if (count > 1) {
                char buffer[BUFFER_SIZE];
                int size = sprintf(buffer, "%d", count);
                for (int i = 0; i < size; i++) {
                    chars[len++] = buffer[i];
                }
            }

            if (i + 1 < charsSize) {
                current = chars[i + 1];
                count = 1;
            }
        } else {
            count++;
        }
    }

    return len;
}