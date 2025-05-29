class Solution:
    def partitionString(self, s: str) -> int:
        count = [0] * 26
        num = 1

        for c in s:
            index = ord(c) - ord("a")

            if count[index] == 1:
                count = [0] * 26
                num += 1

            count[index] += 1

        return num


class Solution:
    def partitionString(self, s: str) -> int:
        mask = 0
        num = 1

        for c in s:
            bit = 1 << (ord(c) - ord("a"))

            if (mask & bit) != 0:
                mask = 0
                num += 1

            mask |= bit

        return num


class Solution:
    def partitionString(self, s: str) -> int:
        sets = set()
        num = 1

        for c in s:
            if c in sets:
                sets.clear()
                num += 1

            sets.add(c)

        return num


class Solution:
    def partitionString(self, s: str) -> int:
        maps = dict()
        num = 1

        for c in s:
            if c in maps:
                maps.clear()
                num += 1

            maps[c] = 1

        return num