from typing import List


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        intervals_size = len(intervals)
        array = [(interval[0], index) for index, interval in enumerate(intervals)]
        array.sort()

        result = [-1] * intervals_size

        for i in range(intervals_size):
            left, right = 0, intervals_size - 1

            while left <= right:
                mid = left + (right - left) // 2

                if intervals[i][1] <= array[mid][0]:
                    result[i] = array[mid][1]
                    right = mid - 1
                else:
                    left = mid + 1

        return result
