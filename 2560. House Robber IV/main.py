from typing import List


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        left = min(nums)
        right = max(nums)

        while left < right:
            mid = (left + right) // 2
            count = 0
            index = 0
            while index < len(nums):
                if nums[index] <= mid:
                    count += 1
                    index += 2
                else:
                    index += 1

            if count >= k:
                right = mid
            else:
                left = mid + 1

        return left


from typing import List


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        left, right = min(nums), max(nums)

        while left < right:
            mid = (left + right) // 2
            if self.canRob(nums, mid, k):
                right = mid
            else:
                left = mid + 1

        return left

    def canRob(self, nums: List[int], cap: int, k: int) -> bool:
        count = 0
        index = 0
        while index < len(nums):
            if nums[index] <= cap:
                count += 1
                index += 2
            else:
                index += 1

        return count >= k
