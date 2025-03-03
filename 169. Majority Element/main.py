from collections import defaultdict
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()

        return nums[len(nums) // 2]


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        major = 0
        count = 0

        for num in nums:
            if count == 0:
                major = num
                count += 1
            else:
                if major == num:
                    count += 1
                else:
                    count -= 1

        return major


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        maps = defaultdict(int)

        for num in nums:
            maps[num] += 1
            if maps[num] > len(nums) // 2:
                return num

        return 0
