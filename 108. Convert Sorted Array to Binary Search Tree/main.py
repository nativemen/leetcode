from typing import List, Optional


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
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = int(len(nums) / 2)
        node = TreeNode(nums[mid])
        node.left = self.sortedArrayToBST(nums[:mid])
        node.right = self.sortedArrayToBST(nums[mid + 1 :])

        return node


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.createTree(nums, 0, len(nums) - 1)

    def createTree(self, nums: List[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None

        mid = int((left + right + 1) / 2)
        node = TreeNode(nums[mid])
        node.left = self.createTree(nums, left, mid - 1)
        node.right = self.createTree(nums, mid + 1, right)

        return node


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.createTree(nums, 0, len(nums) - 1)

    def createTree(self, nums: List[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None

        mid = (left + right + 1) // 2
        node = TreeNode(nums[mid])
        node.left = self.createTree(nums, left, mid - 1)
        node.right = self.createTree(nums, mid + 1, right)

        return node
