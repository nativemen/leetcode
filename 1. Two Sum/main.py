from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = dict()

        for i in range(len(nums)):
            obj = target - nums[i]
            if obj in map:
                return [map[obj], i]
            map[nums[i]] = i

        return []


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = dict()

        for i, num in enumerate(nums):
            obj = target - num
            if obj in map:
                return [map[obj], i]
            map[num] = i

        return []


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums) - 1):
            obj = target - nums[i]
            for j in range(i + 1, len(nums)):
                if nums[j] == obj:
                    return [i, j]

        return []
