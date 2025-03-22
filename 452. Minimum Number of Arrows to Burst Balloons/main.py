from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()

        index = 0

        for point in points:
            if points[index][1] < point[0]:
                index += 1
                points[index][0] = point[0]
                points[index][1] = point[1]
            else:
                points[index][0] = max(points[index][0], point[0])
                points[index][1] = min(points[index][1], point[1])

        return index + 1


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])

        count = 1
        preEnd = points[0][1]

        for point in points:
            if point[0] > preEnd:
                count += 1
                preEnd = point[1]

        return count
