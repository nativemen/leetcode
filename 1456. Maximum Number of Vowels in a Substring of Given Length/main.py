class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        def vowelCheck(c: chr) -> int:
            if c == "a" or c == "e" or c == "i" or c == "o" or c == "u":
                return 1

            return 0

        size = len(s)
        count = 0
        maxCount = 0

        for i in range(size):
            count += vowelCheck(s[i])
            if i >= k:
                count -= vowelCheck(s[i - k])

            maxCount = max(maxCount, count)

        return maxCount


class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        def vowelCheck(c: chr) -> int:
            return 1 if c in "aeiou" else 0

        size = len(s)
        count = 0
        maxCount = 0

        for i in range(size):
            count += vowelCheck(s[i])
            if i >= k:
                count -= vowelCheck(s[i - k])

            maxCount = max(maxCount, count)

        return maxCount


class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = [
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
        ]
        size = len(s)
        count = 0
        maxCount = 0

        for i in range(size):
            count += vowels[ord(s[i]) - ord("a")]
            if i >= k:
                count -= vowels[ord(s[i - k]) - ord("a")]

            maxCount = max(maxCount, count)

        return maxCount


class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {"a", "e", "i", "o", "u"}
        size = len(s)
        count = 0
        maxCount = 0

        for i in range(size):
            count += 1 if s[i] in vowels else 0
            if i >= k:
                count -= 1 if s[i - k] in vowels else 0

            maxCount = max(maxCount, count)

        return maxCount
