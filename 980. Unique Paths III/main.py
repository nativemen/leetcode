from typing import List


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        def dfs(grid: List[List[int]], i: int, j: int, spaces: int) -> int:
            rowSize = len(grid)
            colSize = len(grid[0])

            if i < 0 or i >= rowSize or j < 0 or j >= colSize or grid[i][j] == -1:
                return 0

            if grid[i][j] == 2:
                return 1 if spaces == 0 else 0

            result = 0

            grid[i][j] = -1

            result += dfs(grid, i + 1, j, spaces - 1)
            result += dfs(grid, i - 1, j, spaces - 1)
            result += dfs(grid, i, j + 1, spaces - 1)
            result += dfs(grid, i, j - 1, spaces - 1)

            grid[i][j] = 0

            return result

        rowSize = len(grid)
        colSize = len(grid[0])
        startX = -1
        startY = -1
        spaces = 1

        for i in range(rowSize):
            for j in range(colSize):
                if grid[i][j] == 1:
                    startX = i
                    startY = j
                elif grid[i][j] == 0:
                    spaces += 1

        return dfs(grid, startX, startY, spaces)
