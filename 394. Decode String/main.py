class Solution:
    def decodeString(self, s: str) -> str:
        result = []
        nums = []
        num = 0

        for c in s:
            if c.isdigit():
                num = num * 10 + ord(c) - ord("0")
            elif c == "[":
                result.append(c)
                nums.append(num)
                num = 0
            elif c == "]":
                temp = []
                while result[-1] != "[":
                    temp.insert(0, result[-1])
                    result.pop()
                result.pop()

                number = nums[-1]
                nums.pop()

                for i in range(number):
                    result.extend(temp)
            else:
                result.append(c)

        return "".join(result)


class Solution:
    def decodeString(self, s: str) -> str:
        curStr = ""
        curNum = 0
        stack = []

        for c in s:
            if c.isdigit():
                curNum = curNum * 10 + int(c)
            elif c == "[":
                stack.append((curStr, curNum))
                curNum = 0
                curStr = ""
            elif c == "]":
                (prevStr, num) = stack.pop()
                curStr = prevStr + curStr * num
            else:
                curStr += c

        return curStr
