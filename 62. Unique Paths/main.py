class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m <= 0 or n <= 0:
            return 0

        if m == 1 or n == 1:
            return 1

        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[0][0] = 1

        for i in range(1, m):
            dp[i][0] = dp[i - 1][0]

        for j in range(1, n):
            dp[0][j] = dp[0][j - 1]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m - 1][n - 1]


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m <= 0 or n <= 0:
            return 0

        if m == 1 or n == 1:
            return 1

        dp = [1] * n

        for _ in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j - 1]

        return dp[n - 1]
