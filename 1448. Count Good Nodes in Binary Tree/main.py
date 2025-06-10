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
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, maxVal: int) -> int:
            good = 0

            if not root:
                return good

            if root.val >= maxVal:
                good = 1
                maxVal = root.val

            return good + dfs(root.left, maxVal) + dfs(root.right, maxVal)

        return dfs(root, -float("inf"))