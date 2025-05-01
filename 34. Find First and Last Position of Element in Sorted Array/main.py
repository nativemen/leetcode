from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = [-1, -1]
        size = len(nums)

        for i in range(size):
            if target == nums[i]:
                result[0] = i
                break

        for i in range(size - 1, -1, -1):
            if target == nums[i]:
                result[1] = i
                break

        return result


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = [-1, -1]
        size = len(nums)
        left = 0
        right = size - 1

        while left <= right:
            mid = (left + right) // 2

            if target <= nums[mid]:
                right = mid - 1
            else:
                left = mid + 1

        if left >= size or nums[left] != target:
            return result

        result[0] = left
        right = size - 1

        while left <= right:
            mid = (left + right) // 2

            if target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1

        result[1] = right

        return result
