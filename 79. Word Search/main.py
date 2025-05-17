from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(board: List[List[str]], word: str, index: int, i: int, j: int) -> bool:
            if index == len(word):
                return True

            if (
                i < 0
                or i >= len(board)
                or j < 0
                or j >= len(board[0])
                or board[i][j] != word[index]
            ):
                return False

            board[i][j] = "#"
            r1 = dfs(board, word, index + 1, i - 1, j)
            r2 = dfs(board, word, index + 1, i + 1, j)
            r3 = dfs(board, word, index + 1, i, j - 1)
            r4 = dfs(board, word, index + 1, i, j + 1)
            board[i][j] = word[index]

            return r1 or r2 or r3 or r4

        for i in range(len(board)):
            for j in range(len(board[i])):
                if dfs(board, word, 0, i, j):
                    return True

        return False
