#include "stdio.h"

#define BUFFER_SIZE 10

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize) {
    char **answer = (char **)calloc(n, sizeof(char *));
    if (answer == NULL) {
        return NULL;
    }

    for (int i = 1; i <= n; i++) {
        answer[i - 1] = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (answer[i - 1] == NULL) {
            goto exit;
        }
        if ((i % 3 == 0) && (i % 5 == 0)) {
            sprintf(answer[i - 1], "FizzBuzz");
        } else if (i % 3 == 0) {
            sprintf(answer[i - 1], "Fizz");
        } else if (i % 5 == 0) {
            sprintf(answer[i - 1], "Buzz");
        } else {
            sprintf(answer[i - 1], "%d", i);
        }
    }

    *returnSize = n;
    return answer;

exit:
    for (int i = 0; i < n; i++) {
        if (answer[i] != NULL) {
            free(answer[i]);
            answer[i] = NULL;
        }
    }

    free(answer);
    answer = NULL;
    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize) {
    char **answer = (char **)calloc(n, sizeof(char *));
    if (answer == NULL) {
        return NULL;
    }

    for (int i = 1; i <= n; i++) {
        if ((i % 3 == 0) && (i % 5 == 0)) {
            answer[i - 1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            answer[i - 1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            answer[i - 1] = strdup("Buzz");
        } else {
            char str[BUFFER_SIZE];
            sprintf(str, "%d", i);
            answer[i - 1] = strdup(str);
        }
    }

    *returnSize = n;
    return answer;
}