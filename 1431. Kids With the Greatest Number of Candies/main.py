from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxCandies = max(candies)
        result = []

        for current in candies:
            result.append(current + extraCandies >= maxCandies)

        return result
