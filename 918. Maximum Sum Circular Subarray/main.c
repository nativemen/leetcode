#include <limits.h>
#include <stdio.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int *nums, int numsSize) {
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int curMax = 0;
    int curMin = 0;
    int totalSum = 0;

    for (int i = 0; i < numsSize; i++) {
        curMax = max(curMax + nums[i], nums[i]);
        maxSum = max(maxSum, curMax);
        curMin = min(curMin + nums[i], nums[i]);
        minSum = min(minSum, curMin);
        totalSum += nums[i];
    }

    return (maxSum > 0) ? max(maxSum, totalSum - minSum) : maxSum;
}