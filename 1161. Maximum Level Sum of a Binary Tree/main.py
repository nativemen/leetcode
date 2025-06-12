from collections import deque
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
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        q = deque()
        q.append(root)
        maxSum = -float("inf")
        level = 1
        maxLevel = 1

        while q:
            size = len(q)
            sum = 0

            for i in range(size):
                node = q.popleft()
                sum += node.val

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

            if maxSum < sum:
                maxSum = sum
                maxLevel = level

            level += 1

        return maxLevel
