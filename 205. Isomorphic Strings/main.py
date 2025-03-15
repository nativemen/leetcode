class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        directMapping = dict()
        reverseMapping = dict()

        for i in range(len(s)):
            if s[i] not in directMapping and t[i] not in reverseMapping:
                directMapping[s[i]] = t[i]
                reverseMapping[t[i]] = s[i]
            if (s[i] in directMapping and directMapping[s[i]] != t[i]) or (
                t[i] in reverseMapping and reverseMapping[t[i]] != s[i]
            ):
                return False

        return True


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        directMapping = dict()
        reverseMapping = dict()

        for c1, c2 in zip(s, t):
            if (c1 in directMapping and directMapping[c1] != c2) or (
                c2 in reverseMapping and reverseMapping[c2] != c1
            ):
                return False

            directMapping[c1] = c2
            reverseMapping[c2] = c1

        return True
