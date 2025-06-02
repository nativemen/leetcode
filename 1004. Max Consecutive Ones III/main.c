#include <stdbool.h>
#include <stdio.h>

int longestOnes(int *nums, int numsSize, int k) {
    int maxCount = 0;
    int zeros = 0;
    int slow = 0;
    int fast = 0;

    for (fast = 0; fast < numsSize; fast++) {
        if (nums[fast] == 0) {
            if (zeros == k) {
                if (maxCount < fast - slow) {
                    maxCount = fast - slow;
                }

                while (zeros == k) {
                    if (nums[slow] == 0) {
                        zeros--;
                    }
                    slow++;
                }
            }

            zeros++;
        }
    }

    if (maxCount < fast - slow) {
        maxCount = fast - slow;
    }

    return maxCount;
}

int longestOnes(int *nums, int numsSize, int k) {
    int maxCount = 0;
    int zeros = 0;
    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] == 0) {
            zeros++;
        }

        while (zeros > k) {
            if (nums[slow] == 0) {
                zeros--;
            }
            slow++;
        }

        if (maxCount < fast - slow + 1) {
            maxCount = fast - slow + 1;
        }
    }

    return maxCount;
}