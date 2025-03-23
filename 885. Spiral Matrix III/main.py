from typing import List


class Solution:
    def spiralMatrixIII(
        self, rows: int, cols: int, rStart: int, cStart: int
    ) -> List[List[int]]:
        turnCount = 0
        turn = 0
        turnTotal = 1
        total = rows * cols
        row = rStart
        col = cStart
        left = cStart
        right = cStart
        top = rStart
        bottom = rStart
        direction = 0
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        result = list()

        while len(result) < total:
            if row >= 0 and row < rows and col >= 0 and col < cols:
                result.append([row, col])

            turnCount += 1
            if turnCount == turnTotal:
                turnCount = 0
                turn += 1
                turnTotal = 8 * turn
                left = cStart - turn
                right = cStart + turn
                top = rStart - turn
                bottom = rStart + turn

            nextRow = row + dirs[direction][0]
            nextCol = col + dirs[direction][1]

            if nextRow < top or nextRow > bottom or nextCol < left or nextCol > right:
                direction = (direction + 1) % 4
                nextRow = row + dirs[direction][0]
                nextCol = col + dirs[direction][1]

            row = nextRow
            col = nextCol

        return result


class Solution:
    def spiralMatrixIII(
        self, rows: int, cols: int, rStart: int, cStart: int
    ) -> List[List[int]]:
        total = rows * cols
        step = 1
        row = rStart
        col = cStart
        direction = 0
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        result = list()

        while len(result) < total:
            for repeat in range(2):
                for s in range(step):
                    if row >= 0 and row < rows and col >= 0 and col < cols:
                        result.append([row, col])

                    row += dirs[direction][0]
                    col += dirs[direction][1]
                direction = (direction + 1) % 4
            step += 1

        return result
