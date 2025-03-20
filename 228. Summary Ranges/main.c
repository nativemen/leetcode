#include <stdio.h>

#define ARRAY_SIZE 25

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize) {
    *returnSize = 0;
    if (numsSize == 0) {
        return NULL;
    }

    char **result = (char **)calloc(numsSize, sizeof(char *));
    int count = 0;
    int start = nums[0];

    for (int i = 1; i <= numsSize; i++) {
        if (i == numsSize || nums[i] != nums[i - 1] + 1) {
            result[count] = (char *)calloc(ARRAY_SIZE, sizeof(char));
            if (start == nums[i - 1]) {
                sprintf(result[count], "%d", start);
            } else {
                sprintf(result[count], "%d->%d", start, nums[i - 1]);
            }

            if (i < numsSize) {
                start = nums[i];
            }
            count++;
        }
    }

    *returnSize = count;
    return result;
}

#define ARRAY_SIZE 25

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize) {
    *returnSize = 0;
    if (numsSize == 0) {
        return NULL;
    }

    char **result = (char **)calloc(numsSize, sizeof(char *));

    for (int i = 0; i < numsSize; i++) {
        int start = nums[i];

        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1) {
            i++;
        }

        result[*returnSize] = (char *)calloc(ARRAY_SIZE, sizeof(char));
        if (start == nums[i]) {
            sprintf(result[*returnSize], "%d", start);
        } else {
            sprintf(result[*returnSize], "%d->%d", start, nums[i]);
        }

        *returnSize += 1;
    }

    return result;
}