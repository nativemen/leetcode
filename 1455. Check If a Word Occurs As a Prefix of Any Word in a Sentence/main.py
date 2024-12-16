class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        num = 0
        for word in sentence.split():
            num += 1
            if word.startswith(searchWord):
                return num

        return -1


class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for index, word in enumerate(sentence.split()):
            if word.startswith(searchWord):
                return index + 1

        return -1
