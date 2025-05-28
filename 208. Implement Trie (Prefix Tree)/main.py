class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.isEndOfWord = False

    def insert(self, word: str) -> None:
        node = self

        for c in word:
            index = ord(c) - ord("a")

            if not node.children[index]:
                node.children[index] = Trie()

            node = node.children[index]

        node.isEndOfWord = True

    def search(self, word: str) -> bool:
        node = self

        for c in word:
            index = ord(c) - ord("a")

            if not node.children[index]:
                return False

            node = node.children[index]

        return node.isEndOfWord

    def startsWith(self, prefix: str) -> bool:
        node = self

        for c in prefix:
            index = ord(c) - ord("a")

            if not node.children[index]:
                return False

            node = node.children[index]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


class Trie:
    def __init__(self):
        self.children = dict()
        self.isEndOfWord = False

    def insert(self, word: str) -> None:
        node = self

        for c in word:
            if c not in node.children:
                node.children[c] = Trie()

            node = node.children[c]

        node.isEndOfWord = True

    def search(self, word: str) -> bool:
        node = self

        for c in word:
            if c not in node.children:
                return False

            node = node.children[c]

        return node.isEndOfWord

    def startsWith(self, prefix: str) -> bool:
        node = self

        for c in prefix:
            if c not in node.children:
                return False

            node = node.children[c]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEndOfWord = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root

        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()

            node = node.children[c]

        node.isEndOfWord = True

    def search(self, word: str) -> bool:
        node = self.root

        for c in word:
            if c not in node.children:
                return False

            node = node.children[c]

        return node.isEndOfWord

    def startsWith(self, prefix: str) -> bool:
        node = self.root

        for c in prefix:
            if c not in node.children:
                return False

            node = node.children[c]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)