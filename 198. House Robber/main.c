#include <stdio.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int *dp = (int *)calloc(numsSize, sizeof(int));
    if (dp == NULL) {
        return 0;
    }

    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    int res = dp[numsSize - 1];
    free(dp);
    return res;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int *nums, int numsSize) {
    int a = 0;
    int b = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            a = max(a + nums[i], b);
        } else {
            b = max(a, b + nums[i]);
        }
    }

    return max(a, b);
}