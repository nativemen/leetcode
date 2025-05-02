from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        rowSize = len(triangle)

        if rowSize <= 0:
            return 0

        dp = [[triangle[0][0]]]
        for i in range(1, rowSize):
            dp.append([])
            for j in range(len(triangle[i])):
                if j == 0:
                    dp[i].append(dp[i - 1][0] + triangle[i][0])
                elif j == len(triangle[i]) - 1:
                    dp[i].append(
                        dp[i - 1][len(triangle[i - 1]) - 1]
                        + triangle[i][len(triangle[i]) - 1]
                    )
                else:
                    dp[i].append(min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j])

        return min(dp[rowSize - 1])


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        rowSize = len(triangle)

        if rowSize <= 0:
            return 0

        for i in range(rowSize - 2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])

        return triangle[0][0]
