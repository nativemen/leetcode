from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rowNum = len(matrix)
        colNum = len(matrix[0])
        left = 0
        right = colNum - 1
        top = 0
        bottom = rowNum - 1
        result = list()

        while left <= right and top <= bottom:
            for i in range(left, right + 1):
                result.append(matrix[top][i])
            top += 1

            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1

            if top <= bottom:
                for i in range(right, left - 1, -1):
                    result.append(matrix[bottom][i])
                bottom -= 1

            if left <= right:
                for i in range(bottom, top - 1, -1):
                    result.append(matrix[i][left])
                left += 1

        return result


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rowNum = len(matrix)
        colNum = len(matrix[0])
        left = 0
        right = colNum - 1
        top = 0
        bottom = rowNum - 1
        direction = 1
        result = list()

        while len(result) < rowNum * colNum:
            if direction == 1:
                for i in range(left, right + 1):
                    result.append(matrix[top][i])
                top += 1
                direction = 2
            elif direction == 2:
                for i in range(top, bottom + 1):
                    result.append(matrix[i][right])
                right -= 1
                direction = 3
            elif direction == 3:
                for i in range(right, left - 1, -1):
                    result.append(matrix[bottom][i])
                bottom -= 1
                direction = 4
            else:
                for i in range(bottom, top - 1, -1):
                    result.append(matrix[i][left])
                left += 1
                direction = 1

        return result
