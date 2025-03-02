from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            if nums[left] != val:
                left += 1
                continue

            if nums[right] == val:
                right -= 1
                continue

            nums[left] = nums[right]
            nums[right] = val

        return left


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        remain = []

        for num in nums:
            if num != val:
                remain.append(num)

        nums.clear()

        nums.extend(remain)

        return len(nums)


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        count = 0

        for num in nums:
            if num != val:
                nums[count] = num
                count += 1

        return count
