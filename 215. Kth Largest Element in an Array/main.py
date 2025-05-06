import heapq
import random
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


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = nums[:k]
        heapq.heapify(heap)

        for num in nums[k:]:
            if heap[0] < num:
                heapq.heappop(heap)
                heapq.heappush(heap, num)

        return heap[0]


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if len(nums) == 0 or k < 0 or k > len(nums):
            return -1

        def quickSelect(nums: List[int], k: int) -> int:
            numsSize = len(nums)
            pivot = nums[random.randint(0, len(nums) - 1)]
            i = 0
            left = list()
            right = list()
            mid = list()

            while i < numsSize:
                if nums[i] < pivot:
                    left.append(nums[i])
                elif nums[i] > pivot:
                    right.append(nums[i])
                else:
                    mid.append(nums[i])

                i += 1

            if len(right) >= k:
                return quickSelect(right, k)
            elif len(right) + len(mid) < k:
                return quickSelect(left, k - len(right) - len(mid))
            else:
                return pivot

        return quickSelect(nums, k)
