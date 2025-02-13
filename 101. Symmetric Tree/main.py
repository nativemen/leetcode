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
    NULL_VAL = 1 << 8

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        array = list()

        self.toList(array, root, 1)
        return array == array[::-1]

    def toList(self, array: list, node: Optional[TreeNode], layer: int):
        if node is None:
            array.append(self.NULL_VAL + layer)
            return

        self.toList(array, node.left, layer + 1)
        array.append(node.val)
        self.toList(array, node.right, layer + 1)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        return self.isMirror(root.left, root.right)

    def isMirror(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if left is None or right is None:
            return left == right

        if left.val != right.val:
            return False

        return self.isMirror(left.left, right.right) and self.isMirror(
            left.right, right.left
        )
