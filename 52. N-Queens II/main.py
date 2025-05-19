from typing import List


class Solution:
    def totalNQueens(self, n: int) -> int:
        def getCount(line: List[int], size: int, row: int) -> int:
            def isValid(line: List[int], row: int, col: int) -> bool:
                for i in range(row):
                    if line[i] == col or abs(row - i) == abs(col - line[i]):
                        return False

                return True

            if row == len(line):
                return 1

            count = 0

            for col in range(size):
                if isValid(line, row, col):
                    line[row] = col
                    count += getCount(line, size, row + 1)

            return count

        line = [0] * n

        return getCount(line, n, 0)


class Solution:
    def totalNQueens(self, n: int) -> int:
        def getCount(board: List[List[int]], size: int, row: int) -> int:
            def isValid(board: List[List[int]], row: int, col: int) -> bool:
                for i in range(row + 1):
                    if (
                        board[i][col]
                        or (row - i >= 0 and col - i >= 0 and board[row - i][col - i])
                        or (
                            row - i >= 0
                            and col + i < len(board[row - i])
                            and board[row - i][col + i]
                        )
                    ):
                        return False

                return True

            if row == len(board):
                return 1

            count = 0

            for col in range(size):
                if isValid(board, row, col):
                    board[row][col] = True
                    count += getCount(board, size, row + 1)
                    board[row][col] = False

            return count

        board = [[False for _ in range(n)] for _ in range(n)]

        return getCount(board, n, 0)
