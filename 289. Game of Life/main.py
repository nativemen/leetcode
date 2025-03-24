from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rowSize = len(board)
        colSize = len(board[0])

        for i in range(rowSize):
            for j in range(colSize):
                count = 0

                for m in range(max(0, i - 1), min(rowSize, i + 2)):
                    for n in range(max(0, j - 1), min(colSize, j + 2)):
                        if m != i or n != j:
                            count += board[m][n] & 1

                if ((board[i][j] & 1) == 1 and count == 2) or count == 3:
                    board[i][j] |= 1 << 1

        for i in range(rowSize):
            for j in range(colSize):
                board[i][j] >>= 1
