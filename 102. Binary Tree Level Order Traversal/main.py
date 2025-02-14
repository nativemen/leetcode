import collections
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
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = list()

        self.dfs(res, root, 0)

        return res

    def dfs(self, ans: List[List[int]], node: Optional[TreeNode], layer: int):
        if node is None:
            return

        if len(ans) < layer + 1:
            l = list()
            l.append(node.val)
            ans.append(l)
        else:
            ans[layer].append(node.val)

        self.dfs(ans, node.left, layer + 1)
        self.dfs(ans, node.right, layer + 1)


import queue


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = list()

        if root is None:
            return res

        q = queue.Queue()
        q.put(root)

        while q.qsize() > 0:
            l = list()
            cur_layer_count = q.qsize()
            for i in range(0, cur_layer_count):
                node = q.get()
                l.append(node.val)
                if node.left is not None:
                    q.put(node.left)
                if node.right is not None:
                    q.put(node.right)
            res.append(l)

        return res


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = list()
        q = collections.deque()
        q.append(root)

        while len(q) > 0:
            l = list()
            for i in range(len(q)):
                node = q.popleft()
                if node is not None:
                    l.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if len(l) > 0:
                res.append(l)

        return res
