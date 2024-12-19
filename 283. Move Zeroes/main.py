from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_pos = 0

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[zero_pos] = nums[i]
                zero_pos += 1

        for i in range(zero_pos, len(nums)):
            nums[i] = 0


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero_index = 0

        for i in range(len(nums)):
            if nums[i] != 0:
                temp = nums[non_zero_index]
                nums[non_zero_index] = nums[i]
                nums[i] = temp
                non_zero_index += 1


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero_index = 0

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[non_zero_index], nums[i] = nums[i], nums[non_zero_index]
                non_zero_index += 1


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero = [num for num in nums if num != 0]
        zeros = [0] * (len(nums) - len(non_zero))
        nums[:] = non_zero + zeros


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for num in nums:
            if num == 0:
                nums.remove(0)
                nums.append(0)
