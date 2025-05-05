from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0

        rowSize = len(matrix)
        colSize = len(matrix[0])
        dp = [[0 for _ in range(colSize)] for _ in range(rowSize)]
        maxSize = 0

        for i in range(rowSize):
            for j in range(colSize):
                if matrix[i][j] == "1":
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

                    maxSize = max(maxSize, dp[i][j])

        return maxSize * maxSize
