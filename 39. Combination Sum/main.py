from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        if not candidates or target <= 1:
            return result

        array = []

        def backtrack(candidates: List[int], target: int, index: int):
            if target < 0:
                return

            if target == 0:
                result.append(array.copy())
                return

            for i in range(index, len(candidates)):
                array.append(candidates[i])
                backtrack(candidates, target - candidates[i], i)
                array.pop()

        backtrack(candidates, target, 0)

        return result
