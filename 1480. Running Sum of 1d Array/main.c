#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *runningSum(int *nums, int numsSize, int *returnSize) {
    if ((nums == NULL) || (numsSize <= 0) || (returnSize == NULL)) {
        return NULL;
    }

    int *output = (int *)malloc(numsSize * sizeof(int));
    if (output == NULL) {
        return NULL;
    }

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        output[i] = sum;
    }

    *returnSize = numsSize;
    return output;
}