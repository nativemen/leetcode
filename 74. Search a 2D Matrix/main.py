from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rowSize = len(matrix)
        if rowSize <= 0:
            return False

        colSize = len(matrix[0])
        if colSize <= 0:
            return False

        left = 0
        right = rowSize * colSize - 1

        while left <= right:
            mid = (left + right) // 2
            row = mid // colSize
            col = mid % colSize

            if target < matrix[row][col]:
                right = mid - 1
            elif target > matrix[row][col]:
                left = mid + 1
            else:
                return True

        return False
