from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = list()

        for token in tokens:
            if len(token) > 1 or token.isdigit():
                stack.append(int(token))
            else:
                num2 = stack.pop()
                num1 = stack.pop()

                if token == "+":
                    stack.append(num1 + num2)
                elif token == "-":
                    stack.append(num1 - num2)
                elif token == "*":
                    stack.append(num1 * num2)
                elif token == "/":
                    stack.append(int(num1 / num2))

        return stack.pop()


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = list()

        for token in tokens:
            if token == "+":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(num1 + num2)
            elif token == "-":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(num1 - num2)
            elif token == "*":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(num1 * num2)
            elif token == "/":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(int(num1 / num2))
            else:
                stack.append(int(token))

        return stack.pop()


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = list()

        for token in tokens:
            if token == "+":
                stack[-1] = stack[-2] + stack.pop()
            elif token == "-":
                stack[-1] = stack[-2] - stack.pop()
            elif token == "*":
                stack[-1] = stack[-2] * stack.pop()
            elif token == "/":
                stack[-1] = int(stack[-2] / stack.pop())
            else:
                stack.append(int(token))

        return stack.pop()
