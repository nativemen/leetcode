from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = []

        if not digits:
            return result

        maps = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(index: int, combine: List[str]):
            if index == len(digits):
                result.append("".join(combine))
                return

            for c in maps[digits[index]]:
                combine.append(c)
                backtrack(index + 1, combine)
                combine.pop()

        backtrack(0, [])

        return result


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = []

        if not digits:
            return result

        maps = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(index: int, combine: str):
            if index == len(digits):
                result.append(combine)
                return

            for c in maps[digits[index]]:
                backtrack(index + 1, combine + c)

        backtrack(0, "")

        return result
