import sys
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if nums.count(target) == 0:
            return -1

        return nums.index(target)


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        minVal = sys.maxsize
        index = -1
        size = len(nums)

        for i in range(size):
            if minVal > nums[i]:
                minVal = nums[i]
                index = i

        left = index
        right = index + size - 1

        while left <= right:
            mid = (left + right) // 2

            if target == nums[mid % size]:
                return mid % size
            elif target < nums[mid % size]:
                right = mid - 1
            else:
                left = mid + 1

        return -1


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if target == nums[mid]:
                return mid

            if nums[left] <= nums[mid]:
                if nums[left] <= target and target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1
