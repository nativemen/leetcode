#include <limits.h>
#include <stdio.h>

int findMin(int *nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int findMin(int *nums, int numsSize) {
    int minVal = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (minVal > nums[i]) {
            minVal = nums[i];
        }
    }

    return minVal;
}