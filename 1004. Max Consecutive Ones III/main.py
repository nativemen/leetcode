from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        maxCount = 0
        slow = 0
        zeros = 0
        size = len(nums)

        for fast in range(size):
            if nums[fast] == 0:
                if zeros == k:
                    maxCount = max(maxCount, fast - slow)

                    while zeros == k:
                        if nums[slow] == 0:
                            zeros -= 1
                        slow += 1

                zeros += 1

        return max(maxCount, size - slow)


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        maxCount = 0
        slow = 0
        zeros = 0
        size = len(nums)

        for fast in range(size):
            if nums[fast] == 0:
                zeros += 1

            while zeros > k:
                if nums[slow] == 0:
                    zeros -= 1
                slow += 1

            maxCount = max(maxCount, fast - slow + 1)

        return maxCount
