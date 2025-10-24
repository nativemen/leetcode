#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int findMin(int *nums, int numsSize) {
    int min = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }

    return min;
}

int findMin(int *nums, int numsSize) {
    int min = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }

    return min;
}

int findMin(int *nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            right = mid;
        } else if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right--;
        }
    }

    return nums[right];
}