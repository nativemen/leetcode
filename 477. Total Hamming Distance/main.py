from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        total = 0
        size = len(nums)

        for i in range(32):
            bitCount = 0
            for j in range(size):
                bitCount += (nums[j] >> i) & 1

            total += bitCount * (size - bitCount)

        return total
