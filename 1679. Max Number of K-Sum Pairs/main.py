from collections import defaultdict
from typing import List


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()

        count = 0
        left = 0
        right = len(nums) - 1

        while right >= 0 and nums[right] >= k:
            right -= 1

        while left < right:
            target = k - nums[left]

            if target == nums[right]:
                count += 1
                left += 1
                right -= 1
            elif target < nums[right]:
                right -= 1
            else:
                left += 1

        return count


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        count = 0
        freq = defaultdict(int)

        for i in range(len(nums)):
            if nums[i] < k:
                target = k - nums[i]

                if freq[target] == 0:
                    freq[nums[i]] += 1
                else:
                    count += 1
                    freq[target] -= 1

        return count
