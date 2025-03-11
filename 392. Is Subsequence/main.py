class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s == "" or s == t:
            return True

        si = 0

        for c in t:
            if s[si] == c:
                si += 1

            if si == len(s):
                return True

        return False


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        si = 0
        ti = 0

        while si < len(s) and ti < len(t):
            if s[si] == t[ti]:
                si += 1

            ti += 1

        return si == len(s)
