#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shuffle(int *nums, int numsSize, int n, int *returnSize) {
    int *res = (int *)calloc(2 * n, sizeof(int));
    if (res == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        res[2 * i] = nums[i];
        res[2 * i + 1] = nums[n + i];
    }

    *returnSize = 2 * n;
    return res;
}