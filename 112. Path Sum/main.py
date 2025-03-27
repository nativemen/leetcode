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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        targetSum -= root.val

        if not root.left and not root.right:
            return targetSum == 0

        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(
            root.right, targetSum
        )


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        elif not root.left and not root.right:
            return targetSum == root.val
        elif not root.left:
            return self.hasPathSum(root.right, targetSum - root.val)
        elif not root.right:
            return self.hasPathSum(root.left, targetSum - root.val)
        else:
            return self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(
                root.right, targetSum - root.val
            )


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root: Optional[TreeNode], targetSum: int, currentSum: int) -> bool:
        if not root:
            return False

        currentSum += root.val

        if not root.left and not root.right:
            return targetSum == currentSum

        return self.helper(root.left, targetSum, currentSum) or self.helper(
            root.right, targetSum, currentSum
        )

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return self.helper(root, targetSum, 0)
