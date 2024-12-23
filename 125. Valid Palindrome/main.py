class Solution:
    def isPalindrome(self, s: str) -> bool:
        return self.isEqual(s, 0, len(s) - 1)

    def isEqual(self, s: str, left: int, right: int) -> bool:
        if left >= right:
            return True

        if not s[left].isalnum():
            return self.isEqual(s, left + 1, right)

        if not s[right].isalnum():
            return self.isEqual(s, left, right - 1)

        if s[left].lower() == s[right].lower():
            return self.isEqual(s, left + 1, right - 1)

        return False


class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            if not s[left].isalnum():
                left += 1
                continue

            if not s[right].isalnum():
                right -= 1
                continue

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True


class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = "".join([c.lower() for c in s if c.isalnum()])

        length = len(clean)
        for i in range(0, int(length / 2)):
            if clean[i] != clean[length - 1 - i]:
                return False

        return True


class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = "".join([c.lower() for c in s if c.isalnum()])

        return clean[::-1] == clean


class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = "".join(filter(s.isalnum, s)).lower()

        return clean[::-1] == clean


class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = "".join(filter(str.isalnum, s)).lower()

        return clean[::-1] == clean
