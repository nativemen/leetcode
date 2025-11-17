class Solution:
    def mySqrt(self, x: int) -> int:
        left, right = 0, x

        while left <= right:
            mid = left + (right - left) // 2
            square = mid**2

            if square == x:
                return mid
            elif square < x:
                left = mid + 1
            else:
                right = mid - 1

        return right


class Solution:
    def mySqrt(self, x: int) -> int:
        i = 0

        while i**2 <= x:
            i += 1

        return i - 1
