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
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        result = -1
        count = 0

        def inorder(node: Optional[TreeNode], k: int):
            nonlocal result
            nonlocal count

            if not node:
                return

            inorder(node.left, k)
            count += 1
            if count == k:
                result = node.val
                return
            inorder(node.right, k)

        inorder(root, k)

        return result


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        array = list()

        def inorder(node: Optional[TreeNode]):
            nonlocal array

            if not node:
                return

            inorder(node.left)
            array.append(node.val)
            inorder(node.right)

        inorder(root)

        if k < 1 or k > len(array):
            return -1

        return array[k - 1]
