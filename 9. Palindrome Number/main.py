class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        if x == 0:
            return True

        digit = list()

        while x != 0:
            digit.append(x % 10)
            x //= 10

        left = 0
        right = len(digit) - 1

        while left < right:
            if digit[left] != digit[right]:
                return False
            left += 1
            right -= 1

        return True


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        if x == 0:
            return True

        reverse = 0
        original = x

        while x != 0:
            reverse *= 10
            reverse += x % 10
            x //= 10

        return original == reverse
