class WordDictionary:
    def __init__(self):
        self.children = dict()
        self.isEndOfWord = False

    def addWord(self, word: str) -> None:
        node = self

        for c in word:
            if c not in node.children:
                node.children[c] = WordDictionary()
            node = node.children[c]

        node.isEndOfWord = True

    def search(self, word: str) -> bool:
        node = self
        wordLen = len(word)

        for i in range(wordLen):
            if word[i] == ".":
                for wd in node.children.values():
                    if wd.search(word[i + 1 :]):
                        return True

                return False

            if word[i] not in node.children:
                return False

            node = node.children[word[i]]

        return node.isEndOfWord


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)