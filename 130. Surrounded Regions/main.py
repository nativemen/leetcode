from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def makeOToY(board: List[List[str]], i: int, j: int) -> None:
            if (
                i < 0
                or i >= len(board)
                or j < 0
                or j >= len(board[0])
                or board[i][j] == "X"
                or board[i][j] == "Y"
            ):
                return

            board[i][j] = "Y"

            makeOToY(board, i + 1, j)
            makeOToY(board, i - 1, j)
            makeOToY(board, i, j + 1)
            makeOToY(board, i, j - 1)

        rowSize = len(board)
        colSize = len(board[0])

        for i in range(rowSize):
            for j in range(colSize):
                if i == 0 or i == rowSize - 1 or j == 0 or j == colSize - 1:
                    if board[i][j] == "O":
                        makeOToY(board, i, j)

        for i in range(rowSize):
            for j in range(colSize):
                if board[i][j] == "O":
                    board[i][j] = "X"

                if board[i][j] == "Y":
                    board[i][j] = "O"
