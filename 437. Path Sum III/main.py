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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def calSum(root: Optional[TreeNode], targetSum: int, started: bool) -> int:
            if not root:
                return 0

            count = 0

            if targetSum == root.val:
                count += 1

            if not started:
                count += calSum(root.left, targetSum, started)
                count += calSum(root.right, targetSum, started)

            count += calSum(root.left, targetSum - root.val, True)
            count += calSum(root.right, targetSum - root.val, True)

            return count

        return calSum(root, targetSum, False)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def dfs(root: Optional[TreeNode], targetSum: int, q: List[int]) -> int:
            if not root:
                return 0

            q.append(root.val)

            sum = 0
            count = 0

            for num in q[::-1]:
                sum += num
                if sum == targetSum:
                    count += 1

            count += dfs(root.left, targetSum, q)
            count += dfs(root.right, targetSum, q)

            q.pop()

            return count

        q = []

        return dfs(root, targetSum, q)
