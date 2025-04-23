from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rowSize = len(grid)
        colSize = len(grid[0])

        def makeIslandsZero(grid: List[List[str]], i: int, j: int):
            if i < 0 or i >= rowSize or j < 0 or j >= colSize or grid[i][j] == "0":
                return

            grid[i][j] = "0"

            makeIslandsZero(grid, i - 1, j)
            makeIslandsZero(grid, i + 1, j)
            makeIslandsZero(grid, i, j - 1)
            makeIslandsZero(grid, i, j + 1)

        count = 0

        for i in range(rowSize):
            for j in range(colSize):
                if grid[i][j] == "1":
                    count += 1
                    makeIslandsZero(grid, i, j)

        return count
