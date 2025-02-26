class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        val = 1

        while val < n:
            val *= 4

        if val == n:
            return True

        return False


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n == 1:
            return True

        if n < 1:
            return False

        if n % 4 == 0:
            return self.isPowerOfFour(n / 4)

        return False


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n == 1:
            return True

        if n < 1 or n % 4 != 0:
            return False

        return self.isPowerOfFour(n / 4)


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n < 1:
            return False

        while n % 4 == 0:
            n /= 4

        return n == 1
