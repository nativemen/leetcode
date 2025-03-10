class Solution:
    def longestValidParentheses(self, s: str) -> int:
        result = 0
        left = 0
        right = 0

        for c in s:
            if c == "(":
                left += 1
            else:
                right += 1

            if left == right:
                result = max(result, left + right)
            elif left < right:
                left = 0
                right = 0

        left = 0
        right = 0

        for c in s[::-1]:
            if c == "(":
                left += 1
            else:
                right += 1

            if left == right:
                result = max(result, left + right)
            elif left > right:
                left = 0
                right = 0

        return result
