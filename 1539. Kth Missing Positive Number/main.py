from typing import List


class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        ARRAY_SIZE = 2001
        isMissing = [True] * ARRAY_SIZE

        for num in arr:
            isMissing[num] = False

        for i in range(1, ARRAY_SIZE):
            if not isMissing[i]:
                continue

            k -= 1
            if k <= 0:
                return i

        return -1


class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        left = 0
        right = len(arr) - 1

        while left <= right:
            mid = (left + right) // 2
            if arr[mid] - (mid + 1) < k:
                left = mid + 1
            else:
                right = mid - 1

        return left + k


class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for num in arr:
            if num <= k:
                k += 1

        return k
