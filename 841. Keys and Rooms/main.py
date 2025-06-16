from typing import Deque, List


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        def dfs(index: int):
            nonlocal rooms
            nonlocal visited

            if index < 0 or index >= len(rooms) or visited[index]:
                return

            visited[index] = True

            for room in rooms[index]:
                dfs(room)

        visited = [False] * len(rooms)

        dfs(0)

        return visited == [True] * len(rooms)


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        def dfs(current: int):
            nonlocal rooms
            nonlocal visited

            if current in visited:
                return

            visited.add(current)

            for room in rooms[current]:
                dfs(room)

        visited = set()

        dfs(0)

        return len(visited) == len(rooms)


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        q = Deque()
        q.append(0)
        visited = set()

        while q:
            current = q.popleft()
            visited.add(current)

            for room in rooms[current]:
                if room not in visited:
                    q.append(room)

        return len(visited) == len(rooms)
