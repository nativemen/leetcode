from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)

        result = list()
        result.append(intervals[0])
        index = 0

        for interval in intervals:
            if result[index][1] < interval[0]:
                index += 1
                result.append(interval)
            else:
                result[index][1] = max(result[index][1], interval[1])

        return result
