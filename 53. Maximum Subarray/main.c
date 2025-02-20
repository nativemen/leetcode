#include <limits.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int *nums, int numsSize) {
    int max_sum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum = max(sum + nums[i], nums[i]);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int maxSubArray(int *nums, int numsSize) {
    int max_sum = nums[0];
    int sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (sum < 0) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }

        if (max_sum < sum) {
            max_sum = sum;
        }
    }

    return max_sum;
}

static int maxCrossingSubArray(int *nums, int left, int mid, int right) {
    int left_sum = INT_MIN;
    int sum = 0;

    for (int i = mid; i > left - 1; i--) {
        sum += nums[i];
        left_sum = (left_sum > sum) ? left_sum : sum;
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        right_sum = (right_sum > sum) ? right_sum : sum;
    }

    return left_sum + right_sum;
}

static int maxSubArrayHelper(int *nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = (left + right) / 2;
    int left_max = maxSubArrayHelper(nums, left, mid);
    int right_max = maxSubArrayHelper(nums, mid + 1, right);
    int crossing_max = maxCrossingSubArray(nums, left, mid, right);

    int max = (left_max > right_max) ? left_max : right_max;
    max = (max > crossing_max) ? max : crossing_max;
    return max;
}

int maxSubArray(int *nums, int numsSize) {
    return maxSubArrayHelper(nums, 0, numsSize - 1);
}