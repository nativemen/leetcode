from typing import List


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
