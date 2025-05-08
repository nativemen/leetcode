#include <stdio.h>

#define ARRAY_SIZE 2

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(
        int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (nums1 == NULL || nums2 == NULL || nums1Size <= 0 || nums2Size <= 0 || k <= 0 || k > nums1Size * nums2Size) {
        return NULL;
    }

    int **result = (int **)calloc(k, sizeof(int *));
    *returnColumnSizes = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        (*returnColumnSizes)[i] = ARRAY_SIZE;
    }
    *returnSize = k;

    int i = 0;
    int j = 0;
    int index = 0;

    while (index < k) {
        result[index][0] = nums1[i];
        result[index][1] = nums2[j];
        index++;

        if (i == nums1Size) {
            j++;
        } else if (j == nums2Size) {
            i++;
        } else {
            if (nums1[i + 1] < nums2[j + 1]) {
                i++;
            } else {
                j++;
            }
        }
    }

    return result;
}