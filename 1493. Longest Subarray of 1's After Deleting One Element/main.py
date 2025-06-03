from typing import List


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        size = len(nums)
        slow = 0
        zeros = 0
        maxCount = 0

        for fast in range(size):
            if nums[fast] == 0:
                zeros += 1

            while zeros > 1:
                if nums[slow] == 0:
                    zeros -= 1
                slow += 1

            maxCount = max(maxCount, fast - slow + 1 - zeros)

        if zeros == 0:
            maxCount -= 1

        return maxCount
