from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def hasCycle(adj: List[List[int]], visited: List[int], index: int) -> bool:
            if visited[index] == 1:
                return True

            if visited[index] == 2:
                return False

            visited[index] = 1

            for neighbor in adj[index]:
                if hasCycle(adj, visited, neighbor):
                    return True

            visited[index] = 2

            return False

        if numCourses == 1 or len(prerequisites) <= 1:
            return True

        adj = [[] for _ in range(numCourses)]

        for prerequisite in prerequisites:
            adj[prerequisite[0]].append(prerequisite[1])

        visited = [0] * numCourses

        for i in range(numCourses):
            if hasCycle(adj, visited, i):
                return False

        return True