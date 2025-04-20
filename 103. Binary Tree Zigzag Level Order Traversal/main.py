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
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = list()

        if not root:
            return result

        q = [root]
        leftToRight = True

        while len(q) != 0:
            size = len(q)
            values = list()

            for _ in range(size):
                node = q.pop(0)
                values.append(node.val)

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

            if not leftToRight:
                values.reverse()

            result.append(values)
            leftToRight = not leftToRight

        return result
