class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0

        for i in range(32):
            result <<= 1
            result += n & 1
            n >>= 1

        return result


class Solution:
    def reverseBits(self, n: int) -> int:
        return int(bin(n)[2:].zfill(32)[::-1], 2)
