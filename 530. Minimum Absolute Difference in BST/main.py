import sys
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        minDifference = sys.maxsize
        prevValue = -1

        def inorder(node: Optional[TreeNode]):
            nonlocal minDifference
            nonlocal prevValue

            if not node:
                return

            inorder(node.left)

            if prevValue >= 0:
                minDifference = min(minDifference, abs(node.val - prevValue))

            prevValue = node.val

            inorder(node.right)

        inorder(root)

        return minDifference


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        values = list()

        def dfs(node: Optional[TreeNode]):
            if not node:
                return

            dfs(node.left)
            values.append(node.val)
            dfs(node.right)

        dfs(root)
        minDifference = sys.maxsize

        for i in range(1, len(values)):
            minDifference = min(minDifference, values[i] - values[i - 1])

        return minDifference
