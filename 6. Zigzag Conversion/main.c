#include <stdio.h>

char *convert(char *s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int size = strlen(s);
    char *result = (char *)malloc((size + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < size; j += 2 * (numRows - 1)) {
            result[count++] = s[j];

            if (i > 0 && i < numRows - 1 && j + 2 * (numRows - 1) - 2 * i < size) {
                result[count++] = s[j + 2 * (numRows - 1) - 2 * i];
            }
        }
    }

    result[count] = '\0';

    return result;
}

char *convert(char *s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int *counts = (int *)calloc(numRows, sizeof(int));
    if (counts == NULL) {
        goto exit1;
    }

    char **rows = (char **)calloc(numRows, sizeof(char *));
    if (rows == NULL) {
        goto exit2;
    }

    int size = strlen(s);
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char *)calloc(size + 1, sizeof(char));
        if (rows[i] == NULL) {
            goto exit3;
        }
    }

    int direction = -1;
    int level = 0;
    for (int i = 0; i < size; i++) {
        rows[level][counts[level]++] = s[i];
        if (level % (numRows - 1) == 0) {
            direction *= -1;
        }
        level += direction;
    }

    char *result = (char *)calloc((size + 1), sizeof(char));
    if (result == NULL) {
        goto exit3;
    }

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
    }

    for (int i = 0; i < numRows; i++) {
        if (rows[i] != NULL) {
            free(rows[i]);
            rows[i] = NULL;
        }
    }

    free(rows);
    free(counts);

    return result;

exit3:
    for (int i = 0; i < numRows; i++) {
        if (rows[i] != NULL) {
            free(rows[i]);
            rows[i] = NULL;
        }
    }
    free(rows);
exit2:
    free(counts);
exit1:
    return NULL;
}