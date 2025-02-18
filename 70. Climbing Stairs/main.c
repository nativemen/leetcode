#define ARRAY_SIZE (45 + 1)

int climbStairs(int n) {
    int dp[ARRAY_SIZE] = {0};
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbStairs(int n) {
    if (n <= 1) {
        return 1;
    }

    int a = 1;
    int b = 1;
    int temp;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }

    return b;
}