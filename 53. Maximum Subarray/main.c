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