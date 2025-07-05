from queue import Queue
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = Queue()
        fresh = 0
        rowSize = len(grid)
        colSize = len(grid[0])

        for i in range(rowSize):
            for j in range(colSize):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.put((i, j))

        if fresh == 0:
            return 0

        minutes = -1

        while not q.empty():
            size = q.qsize()

            for _ in range(size):
                x, y = q.get()

                if x > 0 and grid[x - 1][y] == 1:
                    grid[x - 1][y] = 2
                    q.put((x - 1, y))
                    fresh -= 1

                if x < rowSize - 1 and grid[x + 1][y] == 1:
                    grid[x + 1][y] = 2
                    q.put((x + 1, y))
                    fresh -= 1

                if y > 0 and grid[x][y - 1] == 1:
                    grid[x][y - 1] = 2
                    q.put((x, y - 1))
                    fresh -= 1

                if y < colSize - 1 and grid[x][y + 1] == 1:
                    grid[x][y + 1] = 2
                    q.put((x, y + 1))
                    fresh -= 1

            minutes += 1

        if fresh > 0:
            return -1

        return minutes


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = list()
        fresh = 0
        rowSize = len(grid)
        colSize = len(grid[0])

        for i in range(rowSize):
            for j in range(colSize):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))

        if fresh == 0:
            return 0

        minutes = -1

        while len(q) != 0:
            size = len(q)

            for _ in range(size):
                x, y = q.pop(0)

                if x > 0 and grid[x - 1][y] == 1:
                    grid[x - 1][y] = 2
                    q.append((x - 1, y))
                    fresh -= 1

                if x < rowSize - 1 and grid[x + 1][y] == 1:
                    grid[x + 1][y] = 2
                    q.append((x + 1, y))
                    fresh -= 1

                if y > 0 and grid[x][y - 1] == 1:
                    grid[x][y - 1] = 2
                    q.append((x, y - 1))
                    fresh -= 1

                if y < colSize - 1 and grid[x][y + 1] == 1:
                    grid[x][y + 1] = 2
                    q.append((x, y + 1))
                    fresh -= 1

            minutes += 1

        if fresh > 0:
            return -1

        return minutes
