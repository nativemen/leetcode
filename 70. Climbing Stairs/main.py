from collections import defaultdict


class Solution:
    def climbStairs(self, n: int) -> int:
        dp = defaultdict(int)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]


class Solution:
    def climbStairs(self, n: int) -> int:
        dp = dict()
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]


class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1

        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]


class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1

        a = 1
        b = 1
        for i in range(2, n + 1):
            temp = b
            b = a + b
            a = temp

        return b
