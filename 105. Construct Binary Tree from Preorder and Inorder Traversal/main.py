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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0 or len(inorder) == 0:
            return None

        node = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        node.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])
        node.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])

        return node


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        index = 0
        map = dict()

        for i in range(len(inorder)):
            map[inorder[i]] = i

        def helper(start: int, end: int) -> Optional[TreeNode]:
            nonlocal index

            if start > end:
                return None

            current = preorder[index]
            index += 1
            node = TreeNode(current)
            idx = map[current]

            node.left = helper(start, idx - 1)
            node.right = helper(idx + 1, end)

            return node

        return helper(0, len(inorder) - 1)
