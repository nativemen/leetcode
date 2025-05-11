#include <stdio.h>

#define OPTION_MAX_COUNT 4

static void backtrack(char *digit, char *array, char ***result, int *count, int len) {
    if (strlen(array) == len) {
        (*result)[*count] = strdup(array);
        *count += 1;
        return;
    }

    int index = (int)(*digit - '2');
    int arrayLen = strlen(array);
    const char *maps[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (int i = 0; i < strlen(maps[index]); i++) {
        array[arrayLen] = maps[index][i];
        backtrack(digit + 1, array, result, count, len);
        array[arrayLen] = '\0';
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;
    if (digits == NULL || strlen(digits) == 0) {
        return NULL;
    }

    int len = strlen(digits);
    int count = 1;

    for (int i = 0; i < len; i++) {
        count *= OPTION_MAX_COUNT;
    }

    char **result = (char **)calloc(count, sizeof(char *));
    char array[len + 1];
    memset(array, 0, (len + 1) * sizeof(char));
    backtrack(digits, array, &result, returnSize, len);

    return result;
}