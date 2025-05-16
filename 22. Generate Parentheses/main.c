#include <stdio.h>

static void backtrack(char ***result, int *count, char *array, int left, int right) {
    if (left == 0 && right == 0) {
        (*result)[*count] = strdup(array);
        *count += 1;
        return;
    }

    int len = strlen(array);
    if (left > 0) {
        array[len] = '(';
        backtrack(result, count, array, left - 1, right);
        array[len] = '\0';
    }

    if (right > 0 && left < right) {
        array[len] = ')';
        backtrack(result, count, array, left, right - 1);
        array[len] = '\0';
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;
    if (n <= 0) {
        return NULL;
    }

    char **result = (char **)calloc(1 << (n * 2), sizeof(char *));
    char array[n * 2 + 1];
    memset(array, 0, (n * 2 + 1) * sizeof(char));

    backtrack(&result, returnSize, array, n, n);

    return result;
}