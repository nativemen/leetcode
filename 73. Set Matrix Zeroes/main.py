from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rowSize = len(matrix)
        colSize = len(matrix[0])
        firstRowHasZero = False
        firstColHasZero = False

        for j in range(colSize):
            if matrix[0][j] == 0:
                firstRowHasZero = True

        for i in range(rowSize):
            if matrix[i][0] == 0:
                firstColHasZero = True

        for i in range(1, rowSize):
            for j in range(1, colSize):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1, rowSize):
            if matrix[i][0] == 0:
                for j in range(1, colSize):
                    matrix[i][j] = 0

        for j in range(1, colSize):
            if matrix[0][j] == 0:
                for i in range(1, rowSize):
                    matrix[i][j] = 0

        if firstRowHasZero:
            for j in range(colSize):
                matrix[0][j] = 0

        if firstColHasZero:
            for i in range(rowSize):
                matrix[i][0] = 0


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rowSize = len(matrix)
        colSize = len(matrix[0])
        rows = [False] * rowSize
        cols = [False] * colSize

        for i in range(rowSize):
            for j in range(colSize):
                if matrix[i][j] == 0:
                    rows[i] = True
                    cols[j] = True

        for i in range(rowSize):
            if rows[i]:
                for j in range(colSize):
                    matrix[i][j] = 0

        for j in range(colSize):
            if cols[j]:
                for i in range(rowSize):
                    matrix[i][j] = 0


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rowSize = len(matrix)
        colSize = len(matrix[0])
        rows = [False] * rowSize
        cols = [False] * colSize

        for i in range(rowSize):
            for j in range(colSize):
                if matrix[i][j] == 0:
                    rows[i] = True
                    cols[j] = True

        for i in range(rowSize):
            for j in range(colSize):
                if rows[i] or cols[j]:
                    matrix[i][j] = 0


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rowSize = len(matrix)
        colSize = len(matrix[0])
        firstRowHasZero = False
        firstColHasZero = False

        for i in range(rowSize):
            for j in range(colSize):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

                    if i == 0:
                        firstRowHasZero = True
                    if j == 0:
                        firstColHasZero = True

        for i in range(1, rowSize):
            for j in range(1, colSize):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if firstColHasZero:
            for i in range(rowSize):
                matrix[i][0] = 0

        if firstRowHasZero:
            for j in range(colSize):
                matrix[0][j] = 0
