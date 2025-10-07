from typing import List


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0

        for line in grid:
            left, right = 0, len(line) - 1

            while left <= right:
                mid = left + (right - left) // 2

                if line[mid] >= 0:
                    left = mid + 1
                else:
                    right = mid - 1

            count += len(line) - left

        return count
