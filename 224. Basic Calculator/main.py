class Solution:
    def calculate(self, s: str) -> int:
        stack = list()
        num = 0
        sign = 1
        result = 0

        for c in s:
            if c.isdigit():
                num *= 10
                num += ord(c) - ord("0")
            elif c == "+":
                result += sign * num
                num = 0
                sign = 1
            elif c == "-":
                result += sign * num
                num = 0
                sign = -1
            elif c == "(":
                stack.append(result)
                stack.append(sign)
                result = 0
                num = 0
                sign = 1
            elif c == ")":
                result += sign * num
                result *= stack.pop()
                result += stack.pop()
                num = 0
                sign = 1

        return result + sign * num
