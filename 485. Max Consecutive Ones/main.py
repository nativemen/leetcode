from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        maxCount = 0

        for num in nums:
            count = count + 1 if num == 1 else 0
            maxCount = max(maxCount, count)

        return maxCount
