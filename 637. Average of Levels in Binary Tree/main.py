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
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        result = list()

        if not root:
            return result

        q = list()
        q.append(root)

        while q:
            size = len(q)
            value = 0

            for _ in range(size):
                node = q.pop(0)
                value += node.val

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

            result.append(value / size)

        return result


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        info = list()

        def dfs(node: Optional[TreeNode], level: int):
            if not node:
                return

            if len(info) <= level:
                info.append([0, 0])

            info[level][0] += node.val
            info[level][1] += 1

            dfs(node.left, level + 1)
            dfs(node.right, level + 1)

        dfs(root, 0)

        return [value / count for value, count in info]


from collections import deque


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        result = list()

        q = deque()
        q.append(root)

        while q:
            size = len(q)
            value = 0

            for _ in range(size):
                node = q.popleft()
                value += node.val

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

            result.append(value / size)

        return result
