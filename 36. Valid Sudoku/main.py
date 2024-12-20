from collections import defaultdict
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set)

        for row in range(0, len(board)):
            for col in range(0, len(board[row])):
                c = board[row][col]
                if c == '.':
                    continue

                box = ((int)(row / 3)) * 3 + (int)(col / 3)

                if c in rows[row] or c in cols[col] or c in boxes[box]:
                    return False

                rows[row].add(c)
                cols[col].add(c)
                boxes[box].add(c)

        return True


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(list)
        cols = defaultdict(list)
        boxes = defaultdict(list)

        for row in range(0, len(board)):
            for col in range(0, len(board[row])):
                c = board[row][col]
                if c == '.':
                    continue

                box = ((int)(row / 3)) * 3 + (int)(col / 3)

                if c in rows[row] or c in cols[col] or c in boxes[box]:
                    return False

                rows[row].append(c)
                cols[col].append(c)
                boxes[box].append(c)

        return True