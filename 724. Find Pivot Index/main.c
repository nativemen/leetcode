#include <stdbool.h>
#include <stdio.h>

int pivotIndex(int *nums, int numsSize) {
    if (numsSize <= 0) {
        return -1;
    }

    int prefix[numsSize];
    prefix[0] = 0;
    int suffix[numsSize];
    suffix[numsSize - 1] = 0;

    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
        suffix[numsSize - 1 - i] = suffix[numsSize - i] + nums[numsSize - i];
    }

    for (int i = 0; i < numsSize; i++) {
        if (prefix[i] == suffix[i]) {
            return i;
        }
    }

    return -1;
}

int pivotIndex(int *nums, int numsSize) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    int left = 0;

    for (int i = 0; i < numsSize; i++) {
        int right = sum - nums[i] - left;

        if (left == right) {
            return i;
        }

        left += nums[i];
    }

    return -1;
}