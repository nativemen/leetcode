#include <limits.h>

#define ARRAY_SIZE 10000

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int jump(int *nums, int numsSize) {
    int jumps[ARRAY_SIZE];

    for (int i = 0; i < numsSize; i++) {
        jumps[i] = ARRAY_SIZE;
    }

    jumps[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j <= i + nums[i] && j < numsSize; j++) {
            jumps[j] = min(jumps[j], jumps[i] + 1);
        }
    }

    return jumps[numsSize - 1];
}

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int jump(int *nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }

    int jumps = 0;
    int curFarthest = 0;
    int nextFarthest = 0;

    for (int i = 0; i < numsSize; i++) {
        nextFarthest = max(nextFarthest, i + nums[i]);
        if (i == curFarthest) {
            jumps++;
            curFarthest = nextFarthest;
            if (curFarthest >= numsSize - 1) {
                break;
            }
        }
    }

    return jumps;
}

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int jump(int *nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }

    int jumps = 0;
    int left = 0;
    int right = 0;

    while (right < numsSize - 1) {
        int farReach = 0;
        for (int i = left; i <= right; i++) {
            farReach = max(farReach, i + nums[i]);
        }
        left = right + 1;
        right = farReach;
        jumps++;
    }

    return jumps;
}