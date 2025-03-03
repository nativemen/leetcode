#include <stdbool.h>

#define ARRAY_SIZE 10000

bool canJump(int *nums, int numsSize) {
    bool canReach[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        canReach[i] = false;
    }

    canReach[0] = true;
    for (int i = 0; i < numsSize; i++) {
        if (!canReach[i]) {
            return false;
        }

        for (int j = i; j <= i + nums[i] && j < numsSize; j++) {
            canReach[j] = true;
        }
    }

    return true;
}

bool canJump(int *nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            return false;
        }

        maxReach = (maxReach > i + nums[i]) ? maxReach : i + nums[i];
    }

    return true;
}

bool canJump(int *nums, int numsSize) {
    int start = numsSize - 2;
    int target = numsSize - 1;

    while (start >= 0) {
        if (start + nums[start] >= target) {
            target = start;
        }
        start--;
    }

    return target == 0;
}