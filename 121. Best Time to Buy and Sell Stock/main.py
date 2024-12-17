from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProf = 0
        buy = prices[0]

        for price in prices:
            if buy > price:
                buy = price
                continue

            maxProf = max(maxProf, price - buy)

        return maxProf