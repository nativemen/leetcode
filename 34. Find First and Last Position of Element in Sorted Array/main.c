#include <stdio.h>

#define ARRAY_SIZE 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    *returnSize = ARRAY_SIZE;
    result[0] = -1;
    result[1] = -1;

    if (numsSize <= 0 || target < nums[0] || target > nums[numsSize - 1]) {
        return result;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            result[0] = i;
            break;
        }
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == target) {
            result[1] = i;
            break;
        }
    }

    return result;
}

#define ARRAY_SIZE 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    *returnSize = ARRAY_SIZE;
    result[0] = -1;
    result[1] = -1;

    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target <= nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (left >= numsSize || nums[left] != target) {
        return result;
    }

    result[0] = left;
    right = numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    result[1] = right;

    return result;
}