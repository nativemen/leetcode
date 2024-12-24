class Solution:
    def validPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] != s[right]:
                return self.isEqual(s, left + 1, right) or self.isEqual(
                    s, left, right - 1
                )

            left += 1
            right -= 1

        return True

    def isEqual(self, s: str, left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False

            left += 1
            right -= 1

        return True


class Solution:
    def validPalindrome(self, s: str) -> bool:
        return self.isEqual(s, 0, len(s) - 1, False)

    def isEqual(self, s: str, left: int, right: int, skipped: bool) -> bool:
        while left < right:
            if s[left] != s[right]:
                if skipped:
                    return False
                return self.isEqual(s, left + 1, right, True) or self.isEqual(
                    s, left, right - 1, True
                )

            left += 1
            right -= 1

        return True


class Solution:
    def validPalindrome(self, s: str) -> bool:
        return self.isEqual(s, 0, len(s) - 1, False)

    def isEqual(self, s: str, left: int, right: int, skipped: bool) -> bool:
        if left >= right:
            return True

        if s[left] != s[right]:
            if skipped:
                return False
            return self.isEqual(s, left + 1, right, True) or self.isEqual(
                s, left, right - 1, True
            )

        return self.isEqual(s, left + 1, right - 1, skipped)


class Solution:
    def validPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] != s[right]:
                skipR = s[left + 1 : right + 1]
                skipL = s[left:right]

                return skipR == skipR[::-1] or skipL == skipL[::-1]

            left += 1
            right -= 1

        return True
