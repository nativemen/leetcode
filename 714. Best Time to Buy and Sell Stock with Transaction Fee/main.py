from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy = -float("inf")
        profit = 0

        for price in prices:
            buy = max(buy, profit - price)
            profit = max(profit, buy + price - fee)

        return profit
