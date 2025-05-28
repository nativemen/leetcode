import string
from collections import deque
from typing import List


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def word2Hash(word: str) -> int:
            hash = 0
            wordLen = len(word)

            for i in range(wordLen):
                hash = (hash << 5) | (ord(word[i]) - ord("a"))

            return hash

        def genWordTrans(wordHash: int, wordLen: int) -> List[int]:
            wordTrans = []

            for i in range(wordLen):
                mask = 0x1F << (i * 5)

                for j in range(26):
                    transHash = (wordHash & ~mask) | (j << (i * 5))

                    if transHash != wordHash:
                        wordTrans.append(transHash)

            return wordTrans

        wordListSet = set()

        for word in wordList:
            wordListSet.add(word2Hash(word))

        endWordHash = word2Hash(endWord)

        if endWordHash not in wordListSet:
            return 0

        q = deque()
        q.append((word2Hash(beginWord), 1))

        wordLen = len(beginWord)

        while q:
            (currentHash, steps) = q.popleft()

            if currentHash == endWordHash:
                return steps

            wordTrans = genWordTrans(currentHash, wordLen)

            for transHash in wordTrans:
                if transHash in wordListSet:
                    q.append((transHash, steps + 1))
                    wordListSet.discard(transHash)

        return 0


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def isValid(s1: str, s2: str) -> bool:
            len1 = len(s1)
            len2 = len(s2)

            if len1 != len2:
                return False

            diff = 0

            for i in range(len1):
                if s1[i] != s2[i]:
                    diff += 1

            return diff == 1

        if endWord not in wordList:
            return 0

        q = deque()
        q.append((beginWord, 1))

        visited = set()

        while q:
            (currentWord, steps) = q.popleft()

            if currentWord == endWord:
                return steps

            for word in wordList:
                if word not in visited and isValid(currentWord, word):
                    q.append((word, steps + 1))
                    visited.add(word)

        return 0


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def isValid(s1: str, s2: str) -> bool:
            len1 = len(s1)
            len2 = len(s2)

            if len1 != len2:
                return False

            diff = 0

            for i in range(len1):
                if s1[i] != s2[i]:
                    diff += 1

            return diff == 1

        if endWord not in wordList:
            return 0

        q = deque()
        q.append((beginWord, 1))

        visited = [False] * len(wordList)

        while q:
            (currentWord, steps) = q.popleft()

            if currentWord == endWord:
                return steps

            for i in range(len(wordList)):
                if not visited[i] and isValid(currentWord, wordList[i]):
                    q.append((wordList[i], steps + 1))
                    visited[i] = True

        return 0


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordListSet = set(wordList)

        if endWord not in wordListSet:
            return 0

        q = deque()
        q.append((beginWord, 1))

        visited = set([beginWord])

        wordLen = len(beginWord)

        while q:
            (currentWord, steps) = q.popleft()

            if currentWord == endWord:
                return steps

            chars = list(currentWord)

            for i in range(wordLen):
                original = chars[i]

                for c in string.ascii_lowercase:
                    if c == original:
                        continue

                    chars[i] = c
                    word = "".join(chars)
                    if word not in visited and word in wordListSet:
                        q.append((word, steps + 1))
                        visited.add(word)

                chars[i] = original

        return 0


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordListSet = set(wordList)

        if endWord not in wordListSet:
            return 0

        q = deque()
        q.append((beginWord, 1))

        wordLen = len(beginWord)

        while q:
            (currentWord, steps) = q.popleft()

            if currentWord == endWord:
                return steps

            chars = list(currentWord)

            for i in range(wordLen):
                original = chars[i]

                for c in string.ascii_lowercase:
                    if c == original:
                        continue

                    chars[i] = c
                    word = "".join(chars)
                    if word in wordListSet:
                        q.append((word, steps + 1))
                        wordListSet.discard(word)

                chars[i] = original

        return 0
