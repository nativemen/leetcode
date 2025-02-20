from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 1:
            return nums[0]

        dp = [0] * size
        dp[0] = nums[0]
        dp[1] = max(dp[0], nums[1])
        for i in range(2, size):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

        return dp[size - 1]


class Solution:
    def rob(self, nums: List[int]) -> int:
        a = 0
        b = 0

        for i in range(len(nums)):
            if i % 2 == 0:
                a = max(a + nums[i], b)
            else:
                b = max(a, b + nums[i])

        return max(a, b)
