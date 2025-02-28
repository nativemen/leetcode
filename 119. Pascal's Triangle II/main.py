from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        triangle = []

        for i in range(rowIndex + 1):
            row = [1] * (i + 1)
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
            triangle.append(row)

        return triangle[rowIndex]


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        triangle = []

        for i in range(rowIndex + 1):
            triangle.append([1] * (i + 1))

        for i in range(rowIndex + 1):
            for j in range(1, i):
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

        return triangle[rowIndex]


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1] * (rowIndex + 1)
        val = 1

        for i in range(rowIndex + 1):
            row[i] = val
            val = val * (rowIndex - i) // (i + 1)

        return row
