from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []

        if n <= 0 or k <= 0 or k > n:
            return result

        array = []

        def backtrack(n: int, k: int, value: int):
            if len(array) == k:
                result.append(array.copy())
                return

            for i in range(value, n + 1):
                array.append(i)
                backtrack(n, k, i + 1)
                array.pop()

        backtrack(n, k, 1)

        return result


from itertools import combinations


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(combinations(range(1, n + 1), k))
