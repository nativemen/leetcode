from collections import defaultdict
from typing import List


class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        def dfs(current: int):
            nonlocal count

            visited[current] = 1

            for next in maps[current]:
                if visited[abs(next)] == 0:
                    if next > 0:
                        count += 1

                    dfs(abs(next))

        maps = [list() for i in range(n)]

        for c in connections:
            maps[c[0]].append(c[1])
            maps[c[1]].append(-c[0])

        visited = [0] * n
        count = 0

        dfs(0)

        return count


class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        def dfs(current: int):
            nonlocal count

            visited.add(current)
            for neighbor in maps[current]:
                if neighbor not in visited:
                    if (current, neighbor) in directions:
                        count += 1

                    dfs(neighbor)

        maps = defaultdict(list)
        directions = set()

        for src, dest in connections:
            maps[src].append(dest)
            maps[dest].append(src)
            directions.add((src, dest))

        visited = set()
        count = 0

        dfs(0)

        return count
