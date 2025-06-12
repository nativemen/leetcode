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
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def zigZag(root: Optional[TreeNode], goRight: bool, steps: int):
            nonlocal maxCount

            if not root:
                return

            maxCount = max(maxCount, steps)

            if goRight:
                zigZag(root.left, False, steps + 1)
                zigZag(root.right, True, 1)
            else:
                zigZag(root.right, True, steps + 1)
                zigZag(root.left, False, 1)

        if not root:
            return 0

        maxCount = 0

        zigZag(root.right, True, 1)
        zigZag(root.left, False, 1)

        return maxCount


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def zigLeft(root: Optional[TreeNode], steps: int):
            nonlocal maxCount

            if not root:
                return

            maxCount = max(maxCount, steps)
            zigRight(root.right, steps + 1)
            zigLeft(root.left, 1)

        def zigRight(root: Optional[TreeNode], steps: int):
            nonlocal maxCount

            if not root:
                return

            maxCount = max(maxCount, steps)
            zigLeft(root.left, steps + 1)
            zigRight(root.right, 1)

        if not root:
            return 0

        maxCount = 0

        zigRight(root.right, 1)
        zigLeft(root.left, 1)

        return maxCount


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def zigZag(root: Optional[TreeNode], left: int, right: int):
            nonlocal maxCount

            if not root:
                return

            maxCount = max(maxCount, left, right)

            zigZag(root.left, right + 1, 0)
            zigZag(root.right, 0, left + 1)

        if not root:
            return 0

        maxCount = 0

        zigZag(root.right, 0, 1)
        zigZag(root.left, 1, 0)

        return maxCount
