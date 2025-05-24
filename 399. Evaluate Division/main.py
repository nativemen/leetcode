from collections import defaultdict
from typing import Dict, List, Set, Tuple


class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        def dfs(
            maps: Dict[str, List[Tuple[str, float]]],
            visited: Set[str],
            src: str,
            dest: str,
            value: float,
        ):
            nonlocal answer

            visited.add(src)

            if src == dest:
                answer = value
                return

            for s, v in maps[src]:
                if s not in visited:
                    dfs(maps, visited, s, dest, value * v)

            visited.remove(src)

        maps = defaultdict(list)
        for i in range(len(equations)):
            maps[equations[i][0]].append((equations[i][1], values[i]))
            maps[equations[i][1]].append((equations[i][0], 1.0 / values[i]))

        result = list()

        for query in queries:
            if query[0] not in maps or query[1] not in maps:
                result.append(-1.0)
                continue

            visited = set()
            answer = -1.0

            dfs(maps, visited, query[0], query[1], 1.0)

            result.append(answer)

        return result


class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        def find(x: str) -> Tuple[str, float]:
            if x not in maps:
                maps[x] = (x, 1.0)

            (y, valueY) = maps[x]

            if y != x:
                (z, valueZ) = find(y)
                maps[x] = (z, valueY * valueZ)

            return maps[x]

        def union(u: str, v: str, val: float):
            (rootU, valueU) = find(u)
            (rootV, valueV) = find(v)

            if rootU != rootV:
                maps[rootU] = (rootV, val * valueV / valueU)

        maps = defaultdict(list)
        result = list()

        for u, v in queries:
            if u not in maps or v not in maps:
                result.append(-1.0)
                continue

            (rootU, valueU) = find(u)
            (rootV, valueV) = find(v)

            if rootU != rootV:
                result.append(-1.0)
            else:
                result.append(valueU / valueV)

        return result
