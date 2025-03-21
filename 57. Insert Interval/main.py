from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()

        index = 0

        for interval in intervals:
            if intervals[index][1] < interval[0]:
                index += 1
                intervals[index][0] = interval[0]
                intervals[index][1] = interval[1]
            else:
                intervals[index][1] = max(intervals[index][1], interval[1])

        return intervals[: index + 1]


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        result = list()

        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                result.append(newInterval)
                return result + intervals[i:]
            elif newInterval[0] > intervals[i][1]:
                result.append(intervals[i])
            else:
                newInterval = [
                    min(newInterval[0], intervals[i][0]),
                    max(newInterval[1], intervals[i][1]),
                ]

        result.append(newInterval)

        return result
