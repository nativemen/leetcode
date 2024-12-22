from collections import Counter, defaultdict


class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = dict()

        for c in s:
            if c in count:
                count[c] += 1
            else:
                count[c] = 1

        for i, c in enumerate(s):
            if count[c] == 1:
                return i

        return -1


class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = Counter(s)

        for i, c in enumerate(s):
            if count[c] == 1:
                return i

        return -1


class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = defaultdict(int)

        for c in s:
            count[c] += 1

        for i, c in enumerate(s):
            if count[c] == 1:
                return i

        return -1

class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i in range(0, len(s)):
            if s.find(s[i]) == s.rfind(s[i]):
                return i

        return -1
