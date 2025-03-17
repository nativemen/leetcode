from collections import defaultdict
from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = list()

        for num in nums:
            if len(seen) > k:
                seen.pop(0)

            if seen.count(num) > 0:
                return True

            seen.append(num)

        return False


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        maps = dict()

        for i in range(len(nums)):
            if nums[i] in maps and i - maps[nums[i]] <= k:
                return True

            maps[nums[i]] = i

        return False


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        maps = defaultdict(int)

        for i in range(len(nums)):
            if nums[i] in maps and i - maps[nums[i]] <= k:
                return True

            maps[nums[i]] = i

        return False


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        maps = list()

        for i, num in enumerate(nums):
            maps.append((num, i))

        maps.sort()

        for i in range(1, len(maps)):
            if maps[i][0] == maps[i - 1][0] and abs(maps[i][1] - maps[i - 1][1]) <= k:
                return True

        return False
