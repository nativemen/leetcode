from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        s = []

        def backtrack(left: int, right: int):
            if left == 0 and right == 0:
                result.append("".join(s))
                return

            if left > 0:
                s.append("(")
                backtrack(left - 1, right)
                s.pop()

            if right > left:
                s.append(")")
                backtrack(left, right - 1)
                s.pop()

        backtrack(n, n)

        return result


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(left: int, right: int, s=""):
            if left == 0 and right == 0:
                result.append(s)
                return

            if left > 0:
                backtrack(left - 1, right, s + "(")

            if right > left:
                backtrack(left, right - 1, s + ")")

        result = []
        backtrack(n, n, "")

        return result
