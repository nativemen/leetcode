#include <stdbool.h>
#include <stdio.h>

static int compare(const void *a, const void *b) {
    return **(const int **)a - **(const int **)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **insert(int **intervals,
             int intervalsSize,
             int *intervalsColSize,
             int *newInterval,
             int newIntervalSize,
             int *returnSize,
             int **returnColumnSizes) {
    int **result = (int **)calloc(intervalsSize + 1, sizeof(int *));
    *returnColumnSizes = (int *)calloc(intervalsSize + 1, sizeof(int));
    for (size_t i = 0; i < intervalsSize; i++) {
        result[i] = intervals[i];
        (*returnColumnSizes)[i] = intervalsColSize[i];
    }
    result[intervalsSize] = newInterval;
    (*returnColumnSizes)[intervalsSize] = newIntervalSize;
    qsort(result, intervalsSize + 1, sizeof(int *), compare);
    int index = 0;

    for (size_t i = 1; i < intervalsSize + 1; i++) {
        if (result[index][1] < result[i][0]) {
            index++;
            result[index][0] = result[i][0];
            result[index][1] = result[i][1];
        } else {
            result[index][1] = (result[index][1] > result[i][1]) ? result[index][1] : result[i][1];
        }
    }

    *returnSize = index + 1;

    return result;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **insert(int **intervals,
             int intervalsSize,
             int *intervalsColSize,
             int *newInterval,
             int newIntervalSize,
             int *returnSize,
             int **returnColumnSizes) {
    int **result = (int **)calloc(intervalsSize + 1, sizeof(int *));
    *returnColumnSizes = (int *)calloc(intervalsSize + 1, sizeof(int));
    int index = 0;

    for (size_t i = 0; i < intervalsSize; i++) {
        if (newInterval[1] < intervals[i][0]) {
            result[index] = (int *)calloc(newIntervalSize, sizeof(int));
            result[index][0] = newInterval[0];
            result[index][1] = newInterval[1];
            (*returnColumnSizes)[index] = newIntervalSize;
            index++;
            for (size_t j = i; j < intervalsSize; j++) {
                result[index] = (int *)calloc(newIntervalSize, sizeof(int));
                result[index][0] = intervals[j][0];
                result[index][1] = intervals[j][1];
                (*returnColumnSizes)[index] = intervalsColSize[j];
                index++;
            }
            *returnSize = index;

            return result;
        } else if (newInterval[0] > intervals[i][1]) {
            result[index] = (int *)calloc(intervalsColSize[i], sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = intervalsColSize[i];
            index++;
        } else {
            newInterval[0] = (newInterval[0] < intervals[i][0]) ? newInterval[0] : intervals[i][0];
            newInterval[1] = (newInterval[1] > intervals[i][1]) ? newInterval[1] : intervals[i][1];
        }
    }

    result[index] = (int *)calloc(newIntervalSize, sizeof(int));
    result[index][0] = newInterval[0];
    result[index][1] = newInterval[1];
    (*returnColumnSizes)[index] = newIntervalSize;
    index++;

    *returnSize = index;

    return result;
}