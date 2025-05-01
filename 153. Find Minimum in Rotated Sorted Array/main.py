import sys
from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        minVal = sys.maxsize

        for num in nums:
            if minVal > num:
                minVal = num

        return minVal


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = (left + right) // 2
            if nums[mid] <= nums[right]:
                right = mid
            else:
                left = mid + 1

        return nums[left]
