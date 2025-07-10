import heapq
from typing import List


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = []

        for i in range(len(nums1)):
            nums.append((nums1[i], nums2[i]))

        nums.sort(key=lambda x: x[1], reverse=True)

        heap = []
        sum = 0
        result = 0

        for i in range(len(nums)):
            heapq.heappush(heap, nums[i][0])
            sum += nums[i][0]
            while len(heap) > k:
                val = heapq.heappop(heap)
                sum -= val

            if len(heap) == k:
                result = max(result, nums[i][1] * sum)

        return result


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = list(zip(nums1, nums2))
        nums.sort(key=lambda x: x[1], reverse=True)

        heap = []
        sum = 0
        result = 0

        for i in range(len(nums)):
            heapq.heappush(heap, nums[i][0])
            sum += nums[i][0]
            while len(heap) > k:
                val = heapq.heappop(heap)
                sum -= val

            if len(heap) == k:
                result = max(result, nums[i][1] * sum)

        return result
