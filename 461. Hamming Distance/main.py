class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        count = 0
        n = x ^ y

        while n != 0:
            count += n & 1
            n >>= 1

        return count


class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return (x ^ y).bit_count()
