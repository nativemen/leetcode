class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1

        start = 0
        length = len(s)
        while start < length and s[start] == " ":
            start += 1

        sign = 1
        if start < length and s[start] == "-":
            sign = -1
            start += 1
        elif start < length and s[start] == "+":
            start += 1

        num = 0
        for c in s[start:]:
            if not c.isnumeric():
                break

            num = num * 10 + sign * int(c)
            if num > INT_MAX:
                return INT_MAX
            elif num < INT_MIN:
                return INT_MIN

        return num


class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1

        str = s.strip()
        length = len(str)
        start = 0
        sign = 1
        if start < length and str[start] == "-":
            sign = -1
            start += 1
        elif start < length and str[start] == "+":
            start += 1

        num = 0
        for c in str[start:]:
            if not c.isdigit():
                break

            num = num * 10 + sign * int(c)

        if num > INT_MAX:
            return INT_MAX
        elif num < INT_MIN:
            return INT_MIN
        else:
            return num
