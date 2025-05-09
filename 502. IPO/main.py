import heapq
from typing import List


class Solution:
    def findMaximizedCapital(
        self, k: int, w: int, profits: List[int], capital: List[int]
    ) -> int:
        size = len(profits)
        ipo = [(capital[i], profits[i]) for i in range(size)]
        ipo.sort()

        heap = []
        heapq.heapify(heap)
        i = 0

        while k > 0:
            k -= 1
            while i < size and ipo[i][0] <= w:
                heapq.heappush(heap, -ipo[i][1])
                i += 1

            if not heap:
                break

            w -= heapq.heappop(heap)

        return w


class Solution:
    def findMaximizedCapital(
        self, k: int, w: int, profits: List[int], capital: List[int]
    ) -> int:
        ipo = sorted(zip(capital, profits))
        heap = []
        heapq.heapify(heap)
        i = 0
        size = len(profits)

        while k > 0:
            k -= 1
            while i < size and ipo[i][0] <= w:
                heapq.heappush(heap, -ipo[i][1])
                i += 1

            if not heap:
                break

            w -= heapq.heappop(heap)

        return w
