from typing import Counter


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        ALPHABET_SIZE = 26
        freq1 = [0] * ALPHABET_SIZE
        freq2 = [0] * ALPHABET_SIZE

        for c in word1:
            freq1[ord(c) - ord("a")] += 1

        for c in word2:
            freq2[ord(c) - ord("a")] += 1

        for i in range(ALPHABET_SIZE):
            if freq1[i] != freq2[i] and (freq1[i] == 0 or freq2[i] == 0):
                return False

        freq1.sort()
        freq2.sort()

        return freq1 == freq2


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if set(word1) != set(word2):
            return False

        freq1 = Counter(word1)
        freq2 = Counter(word2)

        return sorted(freq1.values()) == sorted(freq2.values())
