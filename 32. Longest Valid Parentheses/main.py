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


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        size = len(s)
        if size == 0:
            return 0

        result = 0
        stack = []
        stack.append(-1)

        for i in range(size):
            if s[i] == "(":
                stack.append(i)
            else:
                if stack:
                    stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    result = max(result, i - stack[-1])

        return result
