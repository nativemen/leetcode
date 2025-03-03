from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 1
        repeat = 0
        prev = nums[0]

        for i in range(1, len(nums)):
            if nums[i] == prev:
                repeat += 1
            else:
                repeat = 0
                prev = nums[i]

            if repeat <= 1:
                nums[count] = nums[i]
                count += 1

        return count


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        size = len(nums)

        if size <= 2:
            return size

        count = 2
        for i in range(2, size):
            if nums[i] != nums[count - 2]:
                nums[count] = nums[i]
                count += 1

        return count
