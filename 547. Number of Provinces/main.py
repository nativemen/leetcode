from typing import List


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(current: int):
            visited[current] = 1

            for j in range(len(isConnected[current])):
                if isConnected[current][j] == 1 and visited[j] == 0:
                    dfs(j)

        visited = [0] * len(isConnected)
        count = 0

        for i in range(len(isConnected)):
            if visited[i] == 0:
                dfs(i)
                count += 1

        return count


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def find(x: int) -> int:
            if parent[x] != x:
                parent[x] = find(parent[x])

            return parent[x]

        def unionSet(x: int, y: int):
            rootX = find(x)
            rootY = find(y)

            if rootX != rootY:
                parent[rootX] = rootY

        parent = [i for i in range(len(isConnected))]

        for i in range(len(isConnected)):
            for j in range(len(isConnected[i])):
                if isConnected[i][j] == 1:
                    unionSet(i, j)

        count = 0

        for i in range(len(parent)):
            if parent[i] == i:
                count += 1

        return count
