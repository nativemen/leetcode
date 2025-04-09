from collections import defaultdict
from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        size = len(points)
        maxPoints = 1

        for i in range(size):
            map = defaultdict(int)
            for j in range(i + 1, size):
                slope = 0.0
                if points[j][0] == points[i][0]:
                    slope = float("inf")
                else:
                    slope = (points[j][1] - points[i][1]) / (
                        points[j][0] - points[i][0]
                    )

                map[slope] += 1

            for value in map.values():
                maxPoints = max(maxPoints, value + 1)

        return maxPoints


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        maxPoints = 1
        size = len(points)

        for i in range(size):
            x1 = points[i][0]
            y1 = points[i][1]
            for j in range(i + 1, size):
                x2 = points[j][0]
                y2 = points[j][1]
                total = 2

                for k in range(size):
                    if k == i or k == j:
                        continue
                    x = points[k][0]
                    y = points[k][1]

                    if (y1 - y) * (x2 - x) == (y2 - y) * (x1 - x):
                        total += 1

                maxPoints = max(maxPoints, total)

        return maxPoints
