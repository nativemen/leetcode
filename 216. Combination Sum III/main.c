#include <stdbool.h>
#include <stdio.h>

static int factorial(int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

static void backtrace(
        bool *visited, int *array, int index, int k, int n, int **result, int *returnSize, int *returnColumnSizes) {
    if (index == k) {
        if (n == 0) {
            result[*returnSize] = (int *)malloc(k * sizeof(int));
            memcpy(result[*returnSize], array, k * sizeof(int));
            returnColumnSizes[*returnSize] = k;
            *returnSize += 1;
        }

        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (visited[i] || (index > 0 && i <= array[index - 1])) {
            continue;
        }

        visited[i] = true;
        array[index] = i;
        backtrace(visited, array, index + 1, k, n - i, result, returnSize, returnColumnSizes);
        visited[i] = false;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes) {
    int size = factorial(9) / (factorial(k) * factorial(9 - k));
    int **result = (int **)malloc(size * sizeof(int *));
    *returnSize = 0;
    if (result == NULL) {
        return NULL;
    }

    *returnColumnSizes = (int *)malloc(size * sizeof(int));
    if (*returnColumnSizes == NULL) {
        free(result);
        return NULL;
    }

    bool visited[10] = {false};
    int array[9] = {0};

    backtrace(visited, array, 0, k, n, result, returnSize, *returnColumnSizes);

    return result;
}

static int factorial(int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

static void backtrace(
        int *array, int index, int k, int n, int start, int **result, int *returnSize, int *returnColumnSizes) {
    if (index == k) {
        if (n == 0) {
            result[*returnSize] = (int *)malloc(k * sizeof(int));
            memcpy(result[*returnSize], array, k * sizeof(int));
            returnColumnSizes[*returnSize] = k;
            *returnSize += 1;
        }

        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > n) {
            break;
        }

        array[index] = i;
        backtrace(array, index + 1, k, n - i, i + 1, result, returnSize, returnColumnSizes);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes) {
    int size = factorial(9) / (factorial(k) * factorial(9 - k));
    int **result = (int **)malloc(size * sizeof(int *));
    *returnSize = 0;
    if (result == NULL) {
        return NULL;
    }

    *returnColumnSizes = (int *)malloc(size * sizeof(int));
    if (*returnColumnSizes == NULL) {
        free(result);
        return NULL;
    }

    int array[9] = {0};

    backtrace(array, 0, k, n, 1, result, returnSize, *returnColumnSizes);

    return result;
}