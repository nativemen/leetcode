#include <stdbool.h>
#include <stdio.h>

#define DP_SIZE 38

int tribonacci(int n) {
    static int dp[DP_SIZE] = {0};

    if (n == 0) {
        dp[n] = 0;
        return 0;
    }

    if (n == 1 || n == 2) {
        dp[n] = 1;
        return 1;
    }

    dp[n] = (dp[n - 1] == 0) ? tribonacci(n - 1) : dp[n - 1];
    dp[n] += (dp[n - 2] == 0) ? tribonacci(n - 2) : dp[n - 2];
    dp[n] += (dp[n - 3] == 0) ? tribonacci(n - 3) : dp[n - 3];

    return dp[n];
}

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}