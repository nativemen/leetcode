#include <limits.h>

int minCapability(int *nums, int numsSize, int k) {
    int left = INT_MAX;
    int right = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < left) {
            left = nums[i];
        }
        if (nums[i] > right) {
            right = nums[i];
        }
    }

    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] <= mid) {
                count++;
                i++;
            }
        }
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int minCapability(int *nums, int numsSize, int k) {
    int left = INT_MAX;
    int right = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < left) {
            left = nums[i];
        }
        if (nums[i] > right) {
            right = nums[i];
        }
    }

    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;
        int index = 0;
        while (index < numsSize) {
            if (nums[index] <= mid) {
                count++;
                index += 2;
            } else {
                index += 1;
            }
        }

        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}