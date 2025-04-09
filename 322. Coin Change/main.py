import sys
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [sys.maxsize] * (amount + 1)
        dp[0] = 0

        for i in range(amount):
            if dp[i] == sys.maxsize:
                continue

            for j in range(len(coins)):
                if coins[j] <= amount - i:
                    dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1)

        if dp[amount] == sys.maxsize:
            return -1

        return dp[amount]


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [sys.maxsize] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            for i in range(coin, amount + 1):
                if dp[i - coin] == sys.maxsize:
                    continue

                dp[i] = min(dp[i], dp[i - coin] + 1)

        if dp[amount] == sys.maxsize:
            return -1

        return dp[amount]
