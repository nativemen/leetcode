from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        size = len(nums)

        if size <= 0:
            return -1

        if size == 1:
            return 0

        for i in range(size - 1):
            if nums[i] > nums[i + 1]:
                return i

        return size - 1


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1

        return left
