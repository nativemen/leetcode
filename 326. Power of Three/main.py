class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        val = 1

        while val < n:
            val *= 3

        if val == n:
            return True

        return False


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True

        if n < 1 or n == 2:
            return False

        if n % 3 == 0:
            return self.isPowerOfThree(n / 3)

        return False


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True

        if n < 1 or n % 3 != 0:
            return False

        return self.isPowerOfThree(n / 3)


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0