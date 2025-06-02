#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

double findMaxAverage(int *nums, int numsSize, int k) {
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int maxSum = sum;

    for (int i = 0; i + k < numsSize; i++) {
        sum += nums[i + k] - nums[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return (double)maxSum / (double)k;
}

double findMaxAverage(int *nums, int numsSize, int k) {
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int maxSum = sum;

    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return (double)maxSum / (double)k;
}