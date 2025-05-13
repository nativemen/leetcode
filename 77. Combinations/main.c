#include <stdio.h>

static unsigned long long factorial(int n) {
    unsigned long long result = 1;

    while (n > 0) {
        result *= n;
        n--;
    }

    return result;
}

static void backtrack(int n, int k, int *array, int index, int ***result, int *colSize, int *count, int value) {
    if (index == k) {
        (*result)[*count] = (int *)malloc(k * sizeof(int));
        colSize[*count] = k;
        memcpy((*result)[*count], array, k * sizeof(int));
        *count += 1;
        return;
    }

    for (int i = value; i <= n; i++) {
        array[index] = i;
        backtrack(n, k, array, index + 1, result, colSize, count, i + 1);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (n <= 0 || k <= 0 || n < k) {
        return NULL;
    }

    int size = (int)(factorial(n) / (factorial(k) * factorial(n - k)));
    int **result = (int **)calloc(size, sizeof(int *));
    *returnColumnSizes = (int *)malloc(size * sizeof(int));
    int array[k];

    backtrack(n, k, array, 0, &result, *returnColumnSizes, returnSize, 1);

    return result;
}