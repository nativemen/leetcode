class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        count = [0] * 26

        for c in magazine:
            count[ord(c) - ord("a")] += 1
        for c in ransomNote:
            count[ord(c) - ord("a")] -= 1
            if count[ord(c) - ord("a")] < 0:
                return False

        return True


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict = {}

        for c in magazine:
            if c not in dict:
                dict[c] = 1
            else:
                dict[c] += 1
        for c in ransomNote:
            if c in dict and dict[c] > 0:
                dict[c] -= 1
            else:
                return False

        return True


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for c in ransomNote:
            if c in magazine:
                magazine = magazine.replace(c, "", 1)
            else:
                return False

        return True
