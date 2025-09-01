class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flips = 0

        while a != 0 or b != 0 or c != 0:
            x, y, z = a & 0x1, b & 0x1, c & 0x1

            if z == 0:
                flips += x + y
            else:
                if (x | y) == 0:
                    flips += 1

            a >>= 1
            b >>= 1
            c >>= 1

        return flips
