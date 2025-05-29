from typing import List, Optional


class Trie:
    def __init__(self):
        self.children = dict()
        self.isEndOfWord = False

    def insertTrie(self, word: str):
        node = self

        for c in word:
            if c not in node.children:
                node.children[c] = Trie()

            node = node.children[c]

        node.isEndOfWord = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(i: int, j: int, word: str, root: Optional[Trie]):
            if root is None:
                return

            if root.isEndOfWord:
                result.append(word)
                root.isEndOfWord = False

            original = board[i][j]
            board[i][j] = "*"

            rowSize = len(board)
            colSize = len(board[0])

            if (
                i + 1 < rowSize
                and board[i + 1][j] != "*"
                and board[i + 1][j] in root.children
            ):
                dfs(i + 1, j, word + board[i + 1][j], root.children[board[i + 1][j]])

            if (
                i - 1 >= 0
                and board[i - 1][j] != "*"
                and board[i - 1][j] in root.children
            ):
                dfs(i - 1, j, word + board[i - 1][j], root.children[board[i - 1][j]])

            if (
                j + 1 < colSize
                and board[i][j + 1] != "*"
                and board[i][j + 1] in root.children
            ):
                dfs(i, j + 1, word + board[i][j + 1], root.children[board[i][j + 1]])

            if (
                j - 1 >= 0
                and board[i][j - 1] != "*"
                and board[i][j - 1] in root.children
            ):
                dfs(i, j - 1, word + board[i][j - 1], root.children[board[i][j - 1]])

            board[i][j] = original

        rowSize = len(board)
        colSize = len(board[0])

        root = Trie()

        for word in words:
            root.insertTrie(word)

        result = []

        for i in range(rowSize):
            for j in range(colSize):
                c = board[i][j]
                if c in root.children:
                    dfs(i, j, c, root.children[c])

        return result


class Trie:
    def __init__(self):
        self.children = dict()
        self.isEndOfWord = False

    def insertTrie(self, word: str):
        node = self

        for c in word:
            if c not in node.children:
                node.children[c] = Trie()

            node = node.children[c]

        node.isEndOfWord = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(i: int, j: int, word: str, root: Optional[Trie]):
            rowSize = len(board)
            colSize = len(board[0])

            if (
                i < 0
                or i >= rowSize
                or j < 0
                or j >= colSize
                or board[i][j] not in root.children
            ):
                return

            original = board[i][j]
            word += original
            root = root.children[board[i][j]]

            if root.isEndOfWord:
                result.add(word)

            board[i][j] = "*"

            dfs(i + 1, j, word, root)
            dfs(i - 1, j, word, root)
            dfs(i, j + 1, word, root)
            dfs(i, j - 1, word, root)

            board[i][j] = original

        rowSize = len(board)
        colSize = len(board[0])

        root = Trie()

        for word in words:
            root.insertTrie(word)

        result = set()

        for i in range(rowSize):
            for j in range(colSize):
                dfs(i, j, "", root)

        return list(result)
