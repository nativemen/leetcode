from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        nums.sort()

        count = 1
        maxCount = 1

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                continue
            elif nums[i] == nums[i - 1] + 1:
                count += 1
            else:
                count = 1
            maxCount = max(maxCount, count)

        return maxCount


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        sets = set(nums)

        maxCount = 1

        for num in sets:
            if num - 1 in sets:
                continue

            count = 1
            last = num

            while last + 1 in sets:
                count += 1
                last += 1

            maxCount = max(maxCount, count)

        return maxCount
