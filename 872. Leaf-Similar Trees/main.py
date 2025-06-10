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
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode], leaves: List[int]):
            if not root:
                return

            if not root.left and not root.right:
                leaves.append(root.val)
                return

            dfs(root.left, leaves)
            dfs(root.right, leaves)

        leaves1 = []
        leaves2 = []

        dfs(root1, leaves1)
        dfs(root2, leaves2)

        return leaves1 == leaves2


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode]) -> List[int]:
            result = []

            if not root:
                return result

            if not root.left and not root.right:
                result.append(root.val)
                return result

            if root.left:
                result.extend(dfs(root.left))
            if root.right:
                result.extend(dfs(root.right))

            return result

        return dfs(root1) == dfs(root2)
