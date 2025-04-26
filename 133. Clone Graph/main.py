from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if node is None:
            return None

        visited = dict()

        def dfs(node: Optional["Node"]) -> Optional["Node"]:
            nonlocal visited

            if node in visited:
                return visited[node]

            visited[node] = Node(node.val)

            for neighbor in node.neighbors:
                visited[node].neighbors.append(dfs(neighbor))

            return visited[node]

        return dfs(node)
