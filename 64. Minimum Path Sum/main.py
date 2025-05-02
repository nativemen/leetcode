from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rowSize = len(grid)
        colSize = len(grid[0])

        for row in range(1, rowSize):
            grid[row][0] += grid[row - 1][0]

        for col in range(1, colSize):
            grid[0][col] += grid[0][col - 1]

        for row in range(1, rowSize):
            for col in range(1, colSize):
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1])

        return grid[rowSize - 1][colSize - 1]
