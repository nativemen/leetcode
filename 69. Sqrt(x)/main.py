class Solution:
    def mySqrt(self, x: int) -> int:
        left = 0
        right = x
        result = 0

        while left <= right:
            mid = (left + right) // 2

            if x == mid * mid:
                result = mid
                break
            elif x > mid * mid:
                result = mid
                left = mid + 1
            else:
                right = mid - 1

        return result