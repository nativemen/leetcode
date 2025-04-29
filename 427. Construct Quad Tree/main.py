from typing import List


class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def construct(self, grid: List[List[int]]) -> "Node":
        def helper(grid: List[List[int]], x: int, y: int, width: int) -> "Node":
            def checkAllSame(grid: List[List[int]], x: int, y: int, width: int) -> bool:
                for i in range(x, x + width):
                    for j in range(y, y + width):
                        if grid[i][j] != grid[x][y]:
                            return False

                return True

            if checkAllSame(grid, x, y, width):
                return Node(grid[x][y] == 1, True)

            node = Node(True, False)
            node.topLeft = helper(grid, x, y, width // 2)
            node.topRight = helper(grid, x, y + width // 2, width // 2)
            node.bottomLeft = helper(grid, x + width // 2, y, width // 2)
            node.bottomRight = helper(grid, x + width // 2, y + width // 2, width // 2)

            return node

        return helper(grid, 0, 0, len(grid))
