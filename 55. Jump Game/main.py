from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        size = len(nums)
        canReach = [False] * size

        canReach[0] = True

        for i in range(size):
            if not canReach[i]:
                return False

            for j in range(i, min(i + nums[i] + 1, size)):
                canReach[j] = True

        return True


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxReach = 0

        for i in range(0, len(nums)):
            if i > maxReach:
                return False

            maxReach = max(maxReach, i + nums[i])

        return True


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        size = len(nums)
        start = size - 2
        target = size - 1

        while start >= 0:
            if start + nums[start] >= target:
                target = start

            start -= 1

        return target == 0


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        size = len(nums)
        target = size - 1

        for start in range(size - 2, -1, -1):
            if start + nums[start] >= target:
                target = start

        return target == 0
