class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        len1 = len(word1)
        len2 = len(word2)

        word = ""
        index = 0

        while index < len1 or index < len2:
            if index < len1:
                word += word1[index]

            if index < len2:
                word += word2[index]

            index += 1

        return word


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        len1 = len(word1)
        len2 = len(word2)

        word = ""
        i = 0
        j = 0

        while i < len1 or j < len2:
            if i < len1:
                word += word1[i]
                i += 1

            if j < len2:
                word += word2[j]
                j += 1

        return word


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        len1 = len(word1)
        len2 = len(word2)
        word = ""

        for index in range(max(len1, len2)):
            if index < len1:
                word += word1[index]

            if index < len2:
                word += word2[index]

        return word
