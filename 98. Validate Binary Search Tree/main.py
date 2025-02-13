from typing import Optional

import numpy as np


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
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, np.iinfo(np.int64).min, np.iinfo(np.int64).max)

    def helper(self, node: Optional[TreeNode], min: np.int64, max: np.int64) -> bool:
        if node is None:
            return True

        if node.val <= min or node.val >= max:
            return False

        return self.helper(node.left, min, node.val) and self.helper(
            node.right, node.val, max
        )


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, float("-inf"), float("inf"))

    def helper(self, node: Optional[TreeNode], min: float, max: float) -> bool:
        if node is None:
            return True

        if node.val <= min or node.val >= max:
            return False

        return self.helper(node.left, min, node.val) and self.helper(
            node.right, node.val, max
        )


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        array = list()
        self.scan(array, root)
        for i in range(1, len(array)):
            if array[i - 1] >= array[i]:
                return False

        return True

    def scan(self, array: list, node: Optional[TreeNode]):
        if node is None:
            return

        self.scan(array, node.left)
        array.append(node.val)
        self.scan(array, node.right)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        array = list()
        self.scan(array, root)
        if array == sorted(array) and len(set(array)) == len(array):
            return True

        return False

    def scan(self, array: list, node: Optional[TreeNode]):
        if node is None:
            return

        self.scan(array, node.left)
        array.append(node.val)
        self.scan(array, node.right)
