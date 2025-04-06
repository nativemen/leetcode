import math
import sys


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if math.fabs(x) < sys.float_info.epsilon:
            return 0.0

        if n == 0:
            return 1.0

        if n < 0:
            return 1 / (x * self.myPow(x, -1 - n))

        power = self.myPow(x, n // 2)

        if n % 2 == 0:
            return power * power

        return x * power * power


class Solution:
    def myPow(self, x: float, n: int) -> float:
        return math.pow(x, n)


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if math.fabs(x) < sys.float_info.epsilon:
            return 0.0

        if n == 0:
            return 1.0

        if n < 0:
            x = 1 / x
            n = -n

        result = 1.0

        while n > 0:
            if n % 2 == 1:
                result *= x

            x *= x
            n //= 2

        return result
