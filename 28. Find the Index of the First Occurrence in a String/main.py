class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle in haystack:
            return haystack.index(needle)

        return -1


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            return haystack.index(needle)
        except:
            return -1


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        len1 = len(haystack)
        len2 = len(needle)

        for i in range(0, len1):
            j = 0
            while j < len2 and i + j < len1 and haystack[i + j] == needle[j]:
                j += 1

            if j == len2:
                return i

        return -1


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        len1 = len(haystack)
        len2 = len(needle)

        if len1 < len2:
            return -1

        for i in range(0, len1 + 1 - len2):
            if haystack[i : i + len2] == needle:
                return i

        return -1
