from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sum = 0

        for n in nums:
            sum += n

        size = len(nums)
        return (size + 1) * size // 2 - sum


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return (len(nums) + 1) * len(nums) // 2 - sum(nums)


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        size = len(nums)
        result = size

        for i in range(size):
            result ^= i ^ nums[i]

        return result


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        size = len(nums)
        result = size

        for i in range(size):
            result += i - nums[i]

        return result


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if i not in nums:
                return i

        return len(nums)


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sorted_nums = sorted(nums)
        for i in range(len(nums)):
            if i != sorted_nums[i]:
                return i

        return len(nums)
