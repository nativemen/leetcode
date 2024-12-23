from collections import Counter, defaultdict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if Counter(s) == Counter(t):
            return True

        return False


import string


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = defaultdict(int)

        for i in range(0, len(s)):
            count[s[i]] += 1
            count[t[i]] -= 1

        for c in string.ascii_lowercase:
            if count[c] != 0:
                return False

        return True


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = dict()

        for i in range(0, len(s)):
            if count.get(s[i]) is None:
                count[s[i]] = 1
            else:
                count[s[i]] += 1
            if count.get(t[i]) is None:
                count[t[i]] = -1
            else:
                count[t[i]] -= 1

        for c in string.ascii_lowercase:
            if count.get(c) is not None and count[c] != 0:
                return False

        return True


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ARRAY_SIZE = 256

        if len(s) != len(t):
            return False

        count = [0] * ARRAY_SIZE

        for i in range(0, len(s)):
            count[ord(s[i])] += 1
            count[ord(t[i])] -= 1

        for i in range(0, ARRAY_SIZE):
            if count[i] != 0:
                return False

        return True
