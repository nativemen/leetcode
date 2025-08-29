from typing import List


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def backtrace(k: int, n: int, start: int):
            if k == 0:
                if n == 0:
                    result.append(array[:])
                return

            for i in range(start, 10):
                if i > n:
                    break

                array.append(i)
                backtrace(k - 1, n - i, i + 1)
                array.pop()

        result = []
        array = []

        backtrace(k, n, 1)

        return result
