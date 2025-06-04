from collections import defaultdict
from typing import List


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rowSize = len(grid)
        colSize = len(grid[0])
        count = 0

        for c in range(colSize):
            column = [grid[r][c] for r in range(rowSize)]

            for r in range(rowSize):
                if grid[r] == column:
                    count += 1

        return count


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        PRIME_BASE = 301
        PRIME_MOD = 100001

        rowSize = len(grid)
        colSize = len(grid[0])
        rowHash = []
        colHash = []

        for r in range(rowSize):
            hash = 0
            for c in range(colSize):
                hash = (hash * PRIME_BASE + grid[r][c]) % PRIME_MOD
            rowHash.append(hash)

        for c in range(colSize):
            hash = 0
            for r in range(rowSize):
                hash = (hash * PRIME_BASE + grid[r][c]) % PRIME_MOD
            colHash.append(hash)

        count = 0

        for i in range(len(rowHash)):
            for j in range(len(colHash)):
                if rowHash[i] == colHash[j]:
                    count += 1

        return count


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rowSize = len(grid)
        colSize = len(grid[0])
        maps = defaultdict(int)
        count = 0

        for r in range(rowSize):
            maps[tuple(grid[r])] += 1

        for c in range(colSize):
            column = []
            for r in range(rowSize):
                column.append(grid[r][c])

            if tuple(column) in maps:
                count += maps[tuple(column)]

        return count
