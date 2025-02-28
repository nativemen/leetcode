class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == "{" or c == "[" or c == "(":
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False

                prev = stack.pop()
                if (
                    (c == "}" and prev != "{")
                    or (c == "]" and prev != "[")
                    or (c == ")" and prev != "(")
                ):
                    return False

        return len(stack) == 0


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c in "{[(":
                stack.append(c)
            else:
                if (
                    len(stack) == 0
                    or (c == "}" and stack[-1] != "{")
                    or (c == "]" and stack[-1] != "[")
                    or (c == ")" and stack[-1] != "(")
                ):
                    return False
                stack.pop()

        return len(stack) == 0


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        valid = {"{": "}", "[": "]", "(": ")"}

        for c in s:
            if c in valid:
                stack.append(c)
            else:
                if len(stack) == 0 or c != valid[stack[-1]]:
                    return False
                stack.pop()

        return len(stack) == 0
