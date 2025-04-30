#include <limits.h>
#include <stdio.h>

int search(int *nums, int numsSize, int target) {
    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
            index = i;
        }
    }

    int left = index;
    int right = left + numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target < nums[mid % numsSize]) {
            right = mid - 1;
        } else if (target > nums[mid % numsSize]) {
            left = mid + 1;
        } else {
            return mid % numsSize;
        }
    }

    return -1;
}

int search(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            if (target >= nums[left]) {
                if (nums[left] <= nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        } else {
            if (target < nums[left]) {
                if (nums[left] <= nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int search(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target == nums[mid]) {
            return mid;
        }

        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}