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


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return self.maxSubArrayHelper(nums, 0, len(nums) - 1)

    def maxSubArrayHelper(self, nums: List[int], left: int, right: int) -> int:
        if left == right:
            return nums[left]

        mid = (left + right) // 2
        left_max = self.maxSubArrayHelper(nums, left, mid)
        right_max = self.maxSubArrayHelper(nums, mid + 1, right)
        cross_max = self.maxCrossingSubArray(nums, left, mid, right)

        return max({left_max, right_max, cross_max})

    def maxCrossingSubArray(
        self, nums: List[int], left: int, mid: int, right: int
    ) -> int:
        left_sum = -sys.maxsize - 1
        sum = 0

        for i in range(mid, left - 1, -1):
            sum += nums[i]
            left_sum = max(left_sum, sum)

        right_sum = -sys.maxsize - 1
        sum = 0
        for i in range(mid + 1, right + 1):
            sum += nums[i]
            right_sum = max(right_sum, sum)

        return left_sum + right_sum


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return self.maxSubArrayHelper(nums, 0, len(nums) - 1)

    def maxSubArrayHelper(self, nums: List[int], left: int, right: int) -> int:
        if left == right:
            return nums[left]

        mid = (left + right) // 2
        left_max = self.maxSubArrayHelper(nums, left, mid)
        right_max = self.maxSubArrayHelper(nums, mid + 1, right)
        cross_max = self.maxCrossingSubArray(nums, left, mid, right)

        return max(left_max, right_max, cross_max)

    def maxCrossingSubArray(
        self, nums: List[int], left: int, mid: int, right: int
    ) -> int:
        left_sum = -sys.maxsize - 1
        sum = 0

        for num in nums[left : mid + 1][::-1]:
            sum += num
            left_sum = max(left_sum, sum)

        right_sum = -sys.maxsize - 1
        sum = 0
        for num in nums[mid + 1 : right + 1]:
            sum += num
            right_sum = max(right_sum, sum)

        return left_sum + right_sum
