#include <stdio.h>

int longestSubarray(int *nums, int numsSize) {
    int zeros = 0;
    int count = 0;
    int maxCount = 0;
    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] == 0) {
            zeros++;
        }

        while (zeros > 1) {
            if (nums[slow] == 0) {
                zeros--;
            }
            slow++;
        }

        if (maxCount < fast - slow + 1 - zeros) {
            maxCount = fast - slow + 1 - zeros;
        }
    }

    if (zeros == 0) {
        maxCount--;
    }

    return maxCount;
}