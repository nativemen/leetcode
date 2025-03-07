#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int prefix[numsSize];
    int suffix[numsSize];
    prefix[0] = 1;
    suffix[numsSize - 1] = 1;

    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = numsSize - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    int *answer = (int *)malloc(numsSize * sizeof(int));
    if (answer == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    *returnSize = numsSize;
    return answer;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int *answer = (int *)malloc(numsSize * sizeof(int));
    if (answer == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int prefix = 1;
    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    *returnSize = numsSize;
    return answer;
}