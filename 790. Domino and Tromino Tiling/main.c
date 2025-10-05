#include <stdbool.h>
#include <stdio.h>

#define MOD 1000000007LL

int numTilings(int n) {
    if (n <= 2) {
        return n;
    }

    if (n == 3) {
        return 5;
    }

    long long *dp = (long long *)malloc(n * sizeof(long long));
    if (dp == NULL) {
        return -1;
    }

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 5;

    for (int i = 3; i < n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
    }

    int result = dp[n - 1];
    free(dp);

    return result;
}
