from typing import List, Tuple


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        def convert(rowSize: int, colSize: int, value: int) -> Tuple[int, int]:
            r = (value - 1) // colSize
            c = (value - 1) % colSize
            x = rowSize - 1 - r
            y = c if r % 2 == 0 else colSize - 1 - c

            return (x, y)

        q = [(1, 0)]
        rowSize = len(board)
        colSize = len(board[0])
        size = rowSize * colSize
        visited = [False] * (size + 1)
        visited[1] = True

        while q:
            item = q.pop(0)
            value = item[0]
            moves = item[1]

            for i in range(1, 7):
                next = value + i

                if next > size:
                    continue

                (x, y) = convert(rowSize, colSize, next)

                if board[x][y] != -1:
                    next = board[x][y]

                if next == size:
                    return moves + 1

                if not visited[next]:
                    visited[next] = True
                    q.append((next, moves + 1))

        return -1
