from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.robHelper(nums[:-1]), self.robHelper(nums[1:]))

    def robHelper(self, nums: List[int]) -> int:
        prev1 = 0
        prev2 = 0

        for i in range(len(nums)):
            cur = max(prev1, prev2 + nums[i])
            prev2 = prev1
            prev1 = cur

        return prev1


class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.robHelper(nums[:-1]), self.robHelper(nums[1:]))

    def robHelper(self, nums: List[int]) -> int:
        a = 0
        b = 0

        for i in range(len(nums)):
            if i % 2 == 0:
                a = max(b, a + nums[i])
            else:
                b = max(a, b + nums[i])

        return max(a, b)


class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.robHelper(nums[:-1]), self.robHelper(nums[1:]))

    def robHelper(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0:
            return 0
        elif size == 1:
            return nums[0]

        dp = [0] * size
        dp[0] = nums[0]
        dp[1] = max(dp[0], nums[1])

        for i in range(2, size):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

        return dp[size - 1]


class Solution:
    def rob(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 1:
            return nums[0]

        return max(
            self.robHelper(nums, 0, size - 2),
            self.robHelper(nums, 1, size - 1),
        )

    def robHelper(self, nums: List[int], left: int, right: int) -> int:
        if left > right:
            return 0

        prev1 = 0
        prev2 = 0

        for i in range(0, right + 1 - left):
            cur = max(prev1, prev2 + nums[left + i])
            prev2 = prev1
            prev1 = cur

        return prev1
