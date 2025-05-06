from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()

        return nums[len(nums) - k]


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        ARRAY_SIZE = 20001
        INDEX_OFFSET = 10000
        count = [0] * ARRAY_SIZE

        for num in nums:
            count[num + INDEX_OFFSET] += 1

        for i in range(ARRAY_SIZE - 1, -1, -1):
            if k <= count[i]:
                return i - INDEX_OFFSET

            k -= count[i]

        return 0 - INDEX_OFFSET
