class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shift = 0

        while left < right:
            left >>= 1
            right >>= 1
            shift += 1

        return left << shift


class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        while left < right:
            right &= right - 1

        return right