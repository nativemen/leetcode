import hashlib
from collections import defaultdict
from typing import List


class Solution:
    def isAllMatched(self, checked: List[int]) -> bool:
        for i in range(len(checked)):
            if checked[i] == 0:
                return False

        return True

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        sLen = len(s)
        wordsSize = len(words)
        wordLen = len(words[0])
        total = wordLen * wordsSize
        result = list()

        if sLen < total:
            return result

        checked = [0] * wordsSize
        searchSize = sLen - total + 1
        for i in range(searchSize):
            offet = i
            subStr = s[offet : offet + wordLen]
            count = 0

            while not self.isAllMatched(checked):
                found = False

                for j in range(wordsSize):
                    if checked[j] == 1:
                        continue

                    if subStr == words[j]:
                        checked[j] = 1
                        count += 1
                        found = True
                        offet += wordLen
                        subStr = s[offet : offet + wordLen]

                if not found:
                    break

            if count == wordsSize:
                result.append(i)

            checked = [0] * wordsSize

        return result


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        wordsSize = len(words)
        wordLen = len(words[0])
        sLen = len(s)
        total = wordLen * wordsSize
        result = list()

        if sLen < total:
            return result

        maps1 = defaultdict(int)

        for i in range(wordsSize):
            maps1[words[i]] += 1

        searchSize = sLen - total + 1
        for i in range(searchSize):
            maps2 = defaultdict(int)
            matched = 0

            for j in range(i, i + total, wordLen):
                subStr = s[j : j + wordLen]

                if subStr not in maps1:
                    break

                maps2[subStr] += 1
                if maps2[subStr] > maps1[subStr]:
                    break

                matched += 1

            if matched == wordsSize:
                result.append(i)

        return result


import hashlib


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        wordsSize = len(words)
        wordLen = len(words[0])
        sLen = len(s)
        total = wordLen * wordsSize
        result = list()

        if sLen < total:
            return result

        targetHash = 0

        for i in range(wordsSize):
            targetHash += int(hashlib.sha256(words[i].encode()).hexdigest(), 16)

        for i in range(wordLen):
            currentHash = 0

            for j in range(wordsSize):
                currentHash += int(
                    hashlib.sha256(
                        s[i + j * wordLen : i + (j + 1) * wordLen].encode()
                    ).hexdigest(),
                    16,
                )

            if currentHash == targetHash:
                result.append(i)

            for j in range(i + wordLen, sLen - total + 1, wordLen):
                currentHash -= int(
                    hashlib.sha256(s[j - wordLen : j].encode()).hexdigest(), 16
                )
                currentHash += int(
                    hashlib.sha256(
                        s[j + total - wordLen : j + total].encode()
                    ).hexdigest(),
                    16,
                )

                if currentHash == targetHash:
                    result.append(j)

        return result
