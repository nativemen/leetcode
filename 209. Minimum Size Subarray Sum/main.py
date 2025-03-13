import sys
from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        result = sys.maxsize
        sum = 0
        left = 0

        for i in range(len(nums)):
            sum += nums[i]

            while sum >= target:
                result = min(result, i - left + 1)
                sum -= nums[left]
                left += 1

        if result == sys.maxsize:
            return 0

        return result


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        result = sys.maxsize
        sum = 0
        left = 0

        for i, num in enumerate(nums):
            sum += num

            while sum >= target:
                result = min(result, i - left + 1)
                sum -= nums[left]
                left += 1

        if result == sys.maxsize:
            return 0

        return result