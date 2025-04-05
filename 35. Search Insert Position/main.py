from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        numsSize = len(nums)

        for i in range(numsSize):
            if nums[i] >= target:
                return i

        return numsSize


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        nums.append(target)
        nums.sort()
        numsSize = len(nums)

        for i in range(numsSize):
            if nums[i] == target:
                return i

        return numsSize


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        nums.append(target)
        nums.sort()

        return nums.index(target)


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        numsSize = len(nums)

        if numsSize == 0:
            return 0

        mid = numsSize // 2

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            return mid + 1 + self.searchInsert(nums[mid + 1 :], target)
        else:
            return self.searchInsert(nums[:mid], target)
