#include <stdbool.h>
#include <stdio.h>

static void backtrack(int ***result, int *count, int *colSize, int *array, int index, int *nums, int numsSize) {
    if (index == numsSize) {
        colSize[*count] = numsSize;
        (*result)[*count] = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            (*result)[*count][i] = array[i];
        }
        *count += 1;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        bool found = false;
        for (int j = 0; j < index; j++) {
            if (array[j] == nums[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            array[index] = nums[i];
            backtrack(result, count, colSize, array, index + 1, nums, numsSize);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (nums == NULL || numsSize <= 0) {
        return NULL;
    }

    int size = 1;

    for (int i = 0; i < numsSize; i++) {
        size *= numsSize - i;
    }

    int **result = (int **)calloc(size, sizeof(int *));
    *returnColumnSizes = (int *)malloc(size * sizeof(int));
    int array[numsSize];

    backtrack(&result, returnSize, *returnColumnSizes, array, 0, nums, numsSize);

    return result;
}