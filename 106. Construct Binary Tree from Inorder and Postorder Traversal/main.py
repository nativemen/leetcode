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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(inorder) == 0 or len(postorder) == 0:
            return None

        node = TreeNode(postorder[-1])
        mid = inorder.index(postorder[-1])
        node.right = self.buildTree(inorder[mid + 1 :], postorder[mid:-1])
        node.left = self.buildTree(inorder[:mid], postorder[:mid])

        return node


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        map = dict()

        for i in range(len(inorder)):
            map[inorder[i]] = i

        index = len(postorder) - 1

        def build(start: int, end: int) -> Optional[TreeNode]:
            nonlocal index

            if start > end:
                return None

            current = postorder[index]
            index -= 1
            node = TreeNode(current)
            mid = map[current]
            node.right = build(mid + 1, end)
            node.left = build(start, mid - 1)

            return node

        return build(0, len(inorder) - 1)
