from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        numsSize = len(nums)

        if numsSize == 0:
            return -1

        prefix = [0] * numsSize
        suffix = [0] * numsSize

        for i in range(1, numsSize):
            prefix[i] = prefix[i - 1] + nums[i - 1]
            suffix[numsSize - 1 - i] = suffix[numsSize - i] + nums[numsSize - i]

        for i in range(numsSize):
            if prefix[i] == suffix[i]:
                return i

        return -1


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        numsSize = len(nums)
        total = sum(nums)
        left = 0

        for i in range(numsSize):
            right = total - nums[i] - left

            if left == right:
                return i

            left += nums[i]

        return -1
