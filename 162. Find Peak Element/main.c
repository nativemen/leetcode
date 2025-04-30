#include <stdio.h>

int findPeakElement(int *nums, int numsSize) {
    if (numsSize <= 0) {
        return -1;
    }

    if (numsSize == 1) {
        return 0;
    }

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }

    return numsSize - 1;
}

int findPeakElement(int *nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}