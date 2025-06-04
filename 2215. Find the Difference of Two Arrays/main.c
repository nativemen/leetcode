#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 2001
#define INDEX_SHIFT 1000
#define RETURN_SIZE 2

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize, int **returnColumnSizes) {
    bool map1[ARRAY_SIZE] = {false};
    bool map2[ARRAY_SIZE] = {false};

    for (int i = 0; i < nums1Size; i++) {
        map1[nums1[i] + INDEX_SHIFT] = true;
    }

    for (int i = 0; i < nums2Size; i++) {
        map2[nums2[i] + INDEX_SHIFT] = true;
    }

    *returnSize = 0;
    int **result = (int **)calloc(RETURN_SIZE, sizeof(int *));
    if (result == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(RETURN_SIZE, sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit2;
    }

    result[0] = (int *)malloc(nums1Size * sizeof(int));
    if (result[0] == NULL) {
        goto exit3;
    }

    result[1] = (int *)malloc(nums2Size * sizeof(int));
    if (result[1] == NULL) {
        goto exit4;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (map1[i] && !map2[i]) {
            result[0][(*returnColumnSizes)[0]++] = i - INDEX_SHIFT;
        } else if (!map1[i] && map2[i]) {
            result[1][(*returnColumnSizes)[1]++] = i - INDEX_SHIFT;
        }
    }

    *returnSize = RETURN_SIZE;

    return result;

exit4:
    free(result[0]);
exit3:
    free(*returnColumnSizes);
exit2:
    free(result);
exit1:
    return NULL;
}