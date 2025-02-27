class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0

        while n != 0:
            count += n & 1
            n >>= 1

        return count


class Solution:
    def hammingWeight(self, n: int) -> int:
        return n.bit_count()
