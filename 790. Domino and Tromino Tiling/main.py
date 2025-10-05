class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7

        if n <= 2:
            return n

        if n == 3:
            return 5

        dp = [0] * n
        dp[0], dp[1], dp[2] = 1, 2, 5

        for i in range(3, n):
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD

        return dp[n - 1]
