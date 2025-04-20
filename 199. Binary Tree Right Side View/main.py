F

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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = list()

        if not root:
            return result

        q = list()
        q.append(root)

        while len(q) != 0:
            size = len(q)
            result.append(q[-1].val)

            for _ in range(size):
                node = q.pop(0)

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

        return result
