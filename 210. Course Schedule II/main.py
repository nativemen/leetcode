from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        for prerequisite in prerequisites:
            adj[prerequisite[0]].append(prerequisite[1])
            indegree[prerequisite[1]] += 1

        q = []

        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        result = []

        while q:
            course = q.pop(0)
            result.append(course)

            for neighbor in adj[course]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        if len(result) != numCourses:
            return []

        result.reverse()

        return result


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        def hasCycle(index: int) -> bool:
            if visited[index] == 1:
                return True

            if visited[index] == 2:
                return False

            visited[index] = 1

            for neighbor in adj[index]:
                if hasCycle(neighbor):
                    return True

            visited[index] = 2
            result.append(index)

            return False

        adj = [[] for _ in range(numCourses)]

        for prerequisite in prerequisites:
            adj[prerequisite[0]].append(prerequisite[1])

        visited = [0] * numCourses
        result = []

        for i in range(numCourses):
            if hasCycle(i):
                return []

        return result
