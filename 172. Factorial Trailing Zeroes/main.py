class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0:
            return 0

        count = 0
        num = n

        while num % 5 == 0:
            count += 1
            num //= 5

        return count + self.trailingZeroes(n - 1)


class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0:
            return 0

        return n // 5 + self.trailingZeroes(n // 5)


class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0

        while n >= 5:
            n //= 5
            count += n

        return count
