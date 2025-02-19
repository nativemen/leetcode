import sys
from collections import defaultdict
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest1 = sys.maxsize
        lowest2 = sys.maxsize
        profit1 = 0
        profit2 = 0

        for price in prices:
            lowest1 = min(lowest1, price)
            profit1 = max(profit1, price - lowest1)
            lowest2 = min(lowest2, price - profit1)
            profit2 = max(profit2, price - lowest2)

        return profit2


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = defaultdict(int)
        right = defaultdict(int)
        size = len(prices)
        lowest = prices[0]

        for i in range(1, size):
            left[i] = max(left[i - 1], prices[i] - lowest)
            lowest = min(lowest, prices[i])

        highest = prices[size - 1]
        for i in range(size - 2, -1, -1):
            right[i] = max(right[i + 1], highest - prices[i])
            highest = max(highest, prices[i])

        max_profit = right[0]
        for i in range(1, size):
            max_profit = max(max_profit, left[i - 1] + right[i])

        return max_profit


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        size = len(prices)
        left = [0] * size
        right = [0] * size
        lowest = prices[0]

        for i in range(1, size):
            left[i] = max(left[i - 1], prices[i] - lowest)
            lowest = min(lowest, prices[i])

        highest = prices[size - 1]
        for i in range(size - 2, -1, -1):
            right[i] = max(right[i + 1], highest - prices[i])
            highest = max(highest, prices[i])

        max_profit = right[0]
        for i in range(1, size):
            max_profit = max(max_profit, left[i - 1] + right[i])

        return max_profit