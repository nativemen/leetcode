import heapq
from typing import List


class Solution:
    def kSmallestPairs(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> List[List[int]]:
        result = []

        if len(nums1) == 0 or len(nums2) == 0 or k <= 0:
            return result

        minHeap = [(num + nums2[0], index, 0) for index, num in enumerate(nums1)]
        heapq.heapify(minHeap)

        while k > 0 and minHeap:
            k -= 1
            (sum, i, j) = heapq.heappop(minHeap)
            result.append([nums1[i], nums2[j]])

            if j + 1 < len(nums2):
                heapq.heappush(minHeap, (nums1[i] + nums2[j + 1], i, j + 1))

        return result


class Solution:
    def kSmallestPairs(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> List[List[int]]:
        result = []
        len1 = len(nums1)
        len2 = len(nums2)

        if len1 == 0 or len2 == 0 or k <= 0:
            return result

        minHeap = [(nums1[0] + nums2[0], 0, 0)]
        heapq.heapify(minHeap)

        while minHeap and k > 0:
            _, i, j = heapq.heappop(minHeap)
            result.append([nums1[i], nums2[j]])
            k -= 1

            if j == 0 and i + 1 < len1:
                heapq.heappush(minHeap, (nums1[i + 1] + nums2[j], i + 1, j))

            if j + 1 < len2:
                heapq.heappush(minHeap, (nums1[i] + nums2[j + 1], i, j + 1))

        return result
