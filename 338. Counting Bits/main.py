from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        counter = [0] * (n + 1)

        for num in range(0, n + 1):
            n = num
            while n != 0:
                counter[num] += n & 1
                n >>= 1

        return counter


class Solution:
    def countBits(self, n: int) -> List[int]:
        counter = [0] * (n + 1)

        for num in range(0, n + 1):
            counter[num] = num.bit_count()

        return counter


class Solution:
    def countBits(self, n: int) -> List[int]:
        counter = [0] * (n + 1)

        for num in range(0, n + 1):
            counter[num] = bin(num).count("1")

        return counter


class Solution:
    def countBits(self, n: int) -> List[int]:
        counter = [0] * (n + 1)

        for num in range(0, n + 1):
            counter[num] = counter[num >> 1] + (num & 1)

        return counter
