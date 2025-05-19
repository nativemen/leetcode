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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            nonlocal maxSum

            if root is None:
                return 0

            left = max(dfs(root.left), 0)
            right = max(dfs(root.right), 0)
            currentSum = left + right + root.val
            maxSum = max(maxSum, currentSum)

            return root.val + max(left, right)

        maxSum = -sys.maxsize

        dfs(root)

        return maxSum
