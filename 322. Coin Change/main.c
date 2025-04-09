#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int coinChange(int *coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    bool dp[amount + 1];
    int count[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = false;
        count[i] = INT_MAX;
    }
    dp[0] = true;
    count[0] = 0;

    for (int i = 0; i < amount; i++) {
        if (!dp[i]) {
            continue;
        }

        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= amount - i) {
                dp[i + coins[j]] = true;
                if (count[i + coins[j]] > count[i] + 1) {
                    count[i + coins[j]] = count[i] + 1;
                }
            }
        }
    }

    if (!dp[amount]) {
        return -1;
    }

    return count[amount];
}

int coinChange(int *coins, int coinsSize, int amount) {
    int dp[amount + 1];

    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i = 0; i < amount; i++) {
        if (dp[i] == INT_MAX) {
            continue;
        }

        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= amount - i) {
                if (dp[i + coins[j]] > dp[i] + 1) {
                    dp[i + coins[j]] = dp[i] + 1;
                }
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;
    }

    return dp[amount];
}