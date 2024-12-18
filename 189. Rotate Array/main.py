from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = k % len(nums)
        nums[:] = nums[-count:] + nums[:-count]


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = k % len(nums)
        nums[-count:] = reversed(nums[-count:])
        nums[:-count] = reversed(nums[:-count])
        nums[:] = reversed(nums[:])
