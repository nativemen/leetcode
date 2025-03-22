from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0] * n for _ in range(n)]
        left = 0
        right = n - 1
        top = 0
        bottom = n - 1
        num = 1

        while left <= right and top <= bottom:
            for i in range(left, right + 1):
                result[top][i] = num
                num += 1
            top += 1

            for i in range(top, bottom + 1):
                result[i][right] = num
                num += 1
            right -= 1

            if top <= bottom:
                for i in range(right, left - 1, -1):
                    result[bottom][i] = num
                    num += 1
                bottom -= 1

            if left <= right:
                for i in range(bottom, top - 1, -1):
                    result[i][left] = num
                    num += 1
                left += 1

        return result


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0] * n for _ in range(n)]
        left = 0
        right = n - 1
        top = 0
        bottom = n - 1
        num = 1
        total = n * n

        while num <= total:
            for i in range(left, right + 1):
                result[top][i] = num
                num += 1
            top += 1

            for i in range(top, bottom + 1):
                result[i][right] = num
                num += 1
            right -= 1

            for i in range(right, left - 1, -1):
                result[bottom][i] = num
                num += 1
            bottom -= 1

            for i in range(bottom, top - 1, -1):
                result[i][left] = num
                num += 1
            left += 1

        return result


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0] * n for _ in range(n)]
        left = 0
        right = n - 1
        top = 0
        bottom = n - 1
        num = 1
        total = n * n
        direction = 1

        while num <= total:
            if direction == 1:
                for i in range(left, right + 1):
                    result[top][i] = num
                    num += 1
                top += 1
                direction = 2
            elif direction == 2:
                for i in range(top, bottom + 1):
                    result[i][right] = num
                    num += 1
                right -= 1
                direction = 3
            elif direction == 3:
                for i in range(right, left - 1, -1):
                    result[bottom][i] = num
                    num += 1
                bottom -= 1
                direction = 4
            else:
                for i in range(bottom, top - 1, -1):
                    result[i][left] = num
                    num += 1
                left += 1
                direction = 1

        return result
