import sys
from typing import List


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        maxSum = 1 - sys.maxsize
        minSum = sys.maxsize
        curMax = 0
        curMin = 0
        totalSum = 0

        for num in nums:
            curMax = max(curMax + num, num)
            maxSum = max(maxSum, curMax)
            curMin = min(curMin + num, num)
            minSum = min(minSum, curMin)
            totalSum += num

        if maxSum < 0:
            return maxSum

        return max(maxSum, totalSum - minSum)
