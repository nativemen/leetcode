#include <stdio.h>

#define ARRAY_SIZE 20
#define RETURN_SIZE 1024

static void backtrack(int *candidates,
                      int candidatesSize,
                      int target,
                      int ***result,
                      int *returnSize,
                      int *colSize,
                      int *array,
                      int count) {
    if (target < 0) {
        return;
    }

    if (target == 0) {
        (*result)[*returnSize] = (int *)malloc(count * sizeof(int));
        memcpy((*result)[*returnSize], array, count * sizeof(int));
        colSize[*returnSize] = count;
        *returnSize += 1;
        return;
    }

    for (int i = 0; i < candidatesSize; i++) {
        if (count == 0 || array[count - 1] <= candidates[i]) {
            array[count] = candidates[i];
            backtrack(
                    candidates, candidatesSize, target - candidates[i], result, returnSize, colSize, array, count + 1);
        }
    }
}

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (candidates == NULL || candidatesSize <= 0 || target <= 1) {
        return NULL;
    }

    int **result = (int **)calloc(RETURN_SIZE, sizeof(int *));
    *returnColumnSizes = (int *)calloc(RETURN_SIZE, sizeof(int));
    int array[ARRAY_SIZE];

    qsort(candidates, candidatesSize, sizeof(int), compare);
    backtrack(candidates, candidatesSize, target, &result, returnSize, *returnColumnSizes, array, 0);

    return result;
}

#define ARRAY_SIZE 20
#define RETURN_SIZE 1024

static void backtrack(int *candidates,
                      int candidatesSize,
                      int target,
                      int index,
                      int ***result,
                      int *returnSize,
                      int *colSize,
                      int *array,
                      int count) {
    if (target < 0) {
        return;
    }

    if (target == 0) {
        (*result)[*returnSize] = (int *)malloc(count * sizeof(int));
        memcpy((*result)[*returnSize], array, count * sizeof(int));
        colSize[*returnSize] = count;
        *returnSize += 1;
        return;
    }

    for (int i = index; i < candidatesSize; i++) {
        array[count] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i, result, returnSize, colSize, array, count + 1);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (candidates == NULL || candidatesSize <= 0 || target <= 1) {
        return NULL;
    }

    int **result = (int **)calloc(RETURN_SIZE, sizeof(int *));
    *returnColumnSizes = (int *)calloc(RETURN_SIZE, sizeof(int));
    int array[ARRAY_SIZE];

    backtrack(candidates, candidatesSize, target, 0, &result, returnSize, *returnColumnSizes, array, 0);

    return result;
}
