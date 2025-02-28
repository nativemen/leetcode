#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    int **array = (int **)calloc(numRows, sizeof(int *));
    if (array == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(numRows, sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit2;
    }

    for (int i = 0; i < numRows; i++) {
        array[i] = (int *)malloc((i + 1) * sizeof(int));
        if (array[i] == NULL) {
            goto exit3;
        }
        (*returnColumnSizes)[i] = i + 1;
        array[i][0] = 1;
        array[i][i] = 1;
        for (int j = 1; j < i; j++) {
            array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
        }
    }

    *returnSize = numRows;

    return array;

exit3:
    for (int i = 0; i < numRows; i++) {
        if (array[i] == NULL) {
            free(array[i]);
            array[i] = NULL;
        }
    }
    free(*returnColumnSizes);
    *returnColumnSizes = NULL;
exit2:
    free(array);
exit1:
    return NULL;
}