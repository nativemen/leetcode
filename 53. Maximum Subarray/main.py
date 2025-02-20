import sys
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = -sys.maxsize - 1
        sum = 0

        for num in nums:
            sum = max(sum + num, num)
            max_sum = max(max_sum, sum)

        return max_sum


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        sum = nums[0]

        for i in range(1, len(nums)):
            if sum < 0:
                sum = nums[i]
            else:
                sum += nums[i]

            max_sum = max(max_sum, sum)

        return max_sum
