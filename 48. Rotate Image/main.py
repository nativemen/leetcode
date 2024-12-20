from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix.reverse()

        for row in range(0, len(matrix)):
            for col in range(row, len(matrix[row])):
                temp = matrix[row][col]
                matrix[row][col] = matrix[col][row]
                matrix[col][row] = temp


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for row in range(0, len(matrix)):
            for col in range(row, len(matrix[row])):
                temp = matrix[row][col]
                matrix[row][col] = matrix[col][row]
                matrix[col][row] = temp

        for row in range(0, len(matrix)):
            for col in range(0, (int)((len(matrix[row]) + 1) / 2)):
                temp = matrix[row][col]
                matrix[row][col] = matrix[row][len(matrix[row]) - 1 - col]
                matrix[row][len(matrix[row]) - 1 - col] = temp
