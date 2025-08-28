from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def canEating(piles: List[int], h: int, k: int) -> bool:
            hours = 0

            for pile in piles:
                hours += (pile + k - 1) // k

            return hours <= h

        left = 1
        right = max(piles)

        while left < right:
            mid = (left + right) // 2

            if canEating(piles, h, mid):
                right = mid
            else:
                left = mid + 1

        return right
