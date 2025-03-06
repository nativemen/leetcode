static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int robHelper(int *nums, int left, int right) {
    if (left > right) {
        return 0;
    }

    int a = 0;
    int b = 0;
    for (int i = left; i <= right; i++) {
        if ((i - left) % 2 == 0) {
            a = max(b, a + nums[i]);
        } else {
            b = max(a, b + nums[i]);
        }
    }

    return max(a, b);
}

int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int a = robHelper(nums, 0, numsSize - 2);
    int b = robHelper(nums, 1, numsSize - 1);

    return max(a, b);
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int robHelper(int *nums, int left, int right) {
    if (left > right) {
        return 0;
    }

    if (left == right) {
        return nums[left];
    }

    int dp[right + 1 - left];
    memset(dp, 0, (right + 1 - left) * sizeof(int));

    dp[0] = nums[left];
    dp[1] = max(dp[0], nums[left + 1]);
    for (int i = 2; i <= right - left; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[left + i]);
    }

    return dp[right - left];
}

int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int a = robHelper(nums, 0, numsSize - 2);
    int b = robHelper(nums, 1, numsSize - 1);

    return max(a, b);
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int robHelper(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int dp[numsSize];

    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[numsSize - 1];
}

int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int a = robHelper(nums, numsSize - 1);
    int b = robHelper(nums + 1, numsSize - 1);

    return max(a, b);
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int robHelper(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int prev1 = 0;
    int prev2 = 0;
    for (int i = 0; i < numsSize; i++) {
        int cur = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int a = robHelper(nums, numsSize - 1);
    int b = robHelper(nums + 1, numsSize - 1);

    return max(a, b);
}