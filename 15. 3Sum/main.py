from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        size = len(nums)

        nums.sort()
        for cur in range(size - 2):
            if cur > 0 and nums[cur] == nums[cur - 1]:
                continue

            left = cur + 1
            right = size - 1

            while left < right:
                sum = nums[cur] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    result.append([nums[cur], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    right -= 1

        return result
