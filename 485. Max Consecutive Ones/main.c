#include <stdbool.h>
#include <stdio.h>

int findMaxConsecutiveOnes(int *nums, int numsSize) {
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
        }

        if ((i == numsSize - 1 || nums[i] == 0) && count != 0) {
            maxCount = (count > maxCount) ? count : maxCount;
            count = 0;
        }
    }

    return maxCount;
}

int findMaxConsecutiveOnes(int *nums, int numsSize) {
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < numsSize; i++) {
        count = (nums[i] == 1) ? count + 1 : 0;

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}