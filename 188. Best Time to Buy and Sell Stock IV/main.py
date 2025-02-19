import sys
from typing import List


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        buys = [sys.maxsize] * k
        profits = [0] * k

        for price in prices:
            prev_profit = 0
            for i in range(0, k):
                if i != 0:
                    prev_profit = profits[i - 1]
                buys[i] = min(buys[i], price - prev_profit)
                profits[i] = max(profits[i], price - buys[i])

        return profits[k - 1]