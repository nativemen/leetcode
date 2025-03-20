from collections import defaultdict
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()

        size = len(nums)

        for i in range(1, size, 3):
            if nums[i] != nums[i - 1]:
                return nums[i - 1]

        return nums[size - 1]


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()

        size = len(nums)
        index = 0

        while index < size - 1:
            if nums[index] != nums[index + 1]:
                return nums[index]

            index += 3

        return nums[size - 1]


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ones = 0
        twos = 0

        for num in nums:
            twos |= ones & num
            ones ^= num

            mask = ~(ones & twos)
            ones &= mask
            twos &= mask

        return ones


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ones = 0
        multi = 0

        for num in nums:
            ones = (num ^ ones) & ~multi
            multi = (num ^ multi) & ~ones

        return ones


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ones = 0
        twos = 0

        for num in nums:
            ones ^= num & ~twos
            twos ^= num & ~ones

        return ones


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        maps = dict()

        for num in nums:
            if num in maps:
                maps[num] += 1
            else:
                maps[num] = 1

        for key, value in maps.items():
            if value == 1:
                return key

        return -1


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        maps = defaultdict(int)

        for num in nums:
            maps[num] += 1

        for key, value in maps.items():
            if value == 1:
                return key

        return -1


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0

        for i in range(32):
            mask = 1 << i
            count = 0

            for num in nums:
                if num & mask != 0:
                    count += 1

            if count % 3 != 0:
                result |= mask

        return result


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        for num in nums:
            if nums.count(num) == 1:
                return num

        return -1
