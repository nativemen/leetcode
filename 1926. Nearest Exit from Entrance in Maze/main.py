from typing import List


class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        q = [(entrance[0], entrance[1])]
        maze[entrance[0]][entrance[1]] = "*"

        count = 0
        rowSize = len(maze)
        colSize = len(maze[0])

        while q:
            size = len(q)

            for i in range(size):
                x, y = q.pop(0)

                if count > 0 and (
                    x == 0 or x == rowSize - 1 or y == 0 or y == colSize - 1
                ):
                    return count

                if x > 0 and maze[x - 1][y] == ".":
                    q.append((x - 1, y))
                    maze[x - 1][y] = "*"

                if x < rowSize - 1 and maze[x + 1][y] == ".":
                    q.append((x + 1, y))
                    maze[x + 1][y] = "*"

                if y > 0 and maze[x][y - 1] == ".":
                    q.append((x, y - 1))
                    maze[x][y - 1] = "*"

                if y < colSize - 1 and maze[x][y + 1] == ".":
                    q.append((x, y + 1))
                    maze[x][y + 1] = "*"

            count += 1

        return -1
