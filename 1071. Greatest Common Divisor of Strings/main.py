import math


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""

        return str1[: math.gcd(len(str1), len(str2))]


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def gcd(a: int, b: int) -> int:
            if b == 0:
                return a

            return gcd(b, a % b)

        if str1 + str2 != str2 + str1:
            return ""

        return str1[: gcd(len(str1), len(str2))]
