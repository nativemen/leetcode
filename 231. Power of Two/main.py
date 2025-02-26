class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        val = 1

        while val < n:
            val *= 2

        if val == n:
            return True

        return False


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        elif n < 1:
            return False
        elif n % 2 == 0:
            return self.isPowerOfTwo(n / 2)
        else:
            return False


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True

        if n < 1 or n % 2 != 0:
            return False

        return self.isPowerOfTwo(n / 2)


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and 1073741824 % n == 0


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0
