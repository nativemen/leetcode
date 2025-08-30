#include <stdbool.h>
#include <stdio.h>

int minCostClimbingStairs(int *cost, int costSize) {
    int dp[costSize + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= costSize; i++) {
        int first = dp[i - 2] + cost[i - 2];
        int second = dp[i - 1] + cost[i - 1];
        dp[i] = (first <= second) ? first : second;
    }

    return dp[costSize];
}