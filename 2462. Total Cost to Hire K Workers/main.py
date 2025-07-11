import heapq
from typing import List


class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        heap1 = []
        heap2 = []
        left = 0
        right = len(costs) - 1

        while left <= right and len(heap1) < candidates:
            heapq.heappush(heap1, costs[left])
            left += 1

        while left <= right and len(heap2) < candidates:
            heapq.heappush(heap2, costs[right])
            right -= 1

        total = 0

        while k > 0:
            if not heap2 or (heap1 and heap1[0] <= heap2[0]):
                total += heapq.heappop(heap1)
                if left <= right:
                    heapq.heappush(heap1, costs[left])
                    left += 1
            elif not heap1 or (heap2 and heap1[0] > heap2[0]):
                total += heapq.heappop(heap2)
                if left <= right:
                    heapq.heappush(heap2, costs[right])
                    right -= 1

            k -= 1

        return total
