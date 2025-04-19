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
    def sum(self, node: Optional[TreeNode], num: int) -> int:
        if not node:
            return 0

        num = num * 10 + node.val

        if not node.left and not node.right:
            return num

        return self.sum(node.left, num) + self.sum(node.right, num)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.sum(root, 0)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:

        def sum(node: Optional[TreeNode], num: int) -> int:
            if not node:
                return 0

            num = num * 10 + node.val

            if not node.left and not node.right:
                return num

            return sum(node.left, num) + sum(node.right, num)

        return sum(root, 0)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:

        def sum(node: Optional[TreeNode], num: int):
            nonlocal total

            if not node:
                return

            num = num * 10 + node.val

            if not node.left and not node.right:
                total += num
                return

            sum(node.left, num)
            sum(node.right, num)

        total = 0

        sum(root, 0)

        return total
