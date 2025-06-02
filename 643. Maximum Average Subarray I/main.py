from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        currentSum = sum(nums[:k])
        maxSum = currentSum

        for i in range(len(nums) - k):
            currentSum += nums[i + k] - nums[i]
            maxSum = max(maxSum, currentSum)

        return maxSum / k


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        currentSum = sum(nums[:k])
        maxSum = currentSum

        for i in range(k, len(nums)):
            currentSum += nums[i] - nums[i - k]
            maxSum = max(maxSum, currentSum)

        return maxSum / k
