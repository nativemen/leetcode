import sys
from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        jumps = [sys.maxsize] * size

        jumps[0] = 0
        for i in range(size):
            for j in range(i + 1, min(nums[i] + i + 1, size)):
                jumps[j] = min(jumps[j], jumps[i] + 1)

        return jumps[size - 1]


class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size <= 1:
            return 0

        cur_farthest = 0
        next_farthest = 0
        jumps = 0

        for i in range(size):
            next_farthest = max(next_farthest, i + nums[i])
            if i == cur_farthest:
                jumps += 1
                cur_farthest = next_farthest
                if cur_farthest >= size - 1:
                    break

        return jumps


class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        jumps = 0
        left = 0
        right = 0

        while right < size - 1:
            far_reach = 0
            for i in range(left, right + 1):
                far_reach = max(far_reach, i + nums[i])

            left = right + 1
            right = far_reach
            jumps += 1

        return jumps
