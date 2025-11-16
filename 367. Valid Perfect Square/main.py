class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left = 1
        right = num

        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid

            if square == num:
                return True
            elif square < num:
                left = mid + 1
            else:
                right = mid - 1

        return False


class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        for i in range(num + 1):
            square = i * i
            if square == num:
                return True
            elif square > num:
                break

        return False
