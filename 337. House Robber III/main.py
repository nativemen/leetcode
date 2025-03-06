from typing import Optional, Tuple


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
    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.robHelper(root))

    def robHelper(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if root is None:
            return (0, 0)

        left = self.robHelper(root.left)
        right = self.robHelper(root.right)
        with_root = root.val + left[1] + right[1]
        without_root = max(left) + max(right)

        return (with_root, without_root)
