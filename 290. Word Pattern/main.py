class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        patternLen = len(pattern)
        wordsLen = len(words)

        if patternLen != wordsLen:
            return False

        directMapping = dict()
        reverseMapping = dict()

        for i in range(patternLen):
            if (
                pattern[i] in directMapping and directMapping[pattern[i]] != words[i]
            ) or (
                words[i] in reverseMapping and reverseMapping[words[i]] != pattern[i]
            ):
                return False

            directMapping[pattern[i]] = words[i]
            reverseMapping[words[i]] = pattern[i]

        return True


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        patternLen = len(pattern)
        wordsLen = len(words)

        if patternLen != wordsLen:
            return False

        HASHMAP_SIZE = 26
        hashmap = [""] * HASHMAP_SIZE

        for i in range(patternLen):
            index = ord(pattern[i]) - ord("a")
            if hashmap[index]:
                if hashmap[index] != words[i]:
                    return False
            else:
                for j in range(HASHMAP_SIZE):
                    if hashmap[j] == words[i]:
                        return False
                hashmap[index] = words[i]

        return True


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        patternLen = len(pattern)
        wordsLen = len(words)

        if patternLen != wordsLen:
            return False

        HASHMAP_SIZE = 26
        hashmap = [""] * HASHMAP_SIZE

        for i in range(patternLen):
            index = ord(pattern[i]) - ord("a")
            if hashmap[index]:
                if hashmap[index] != words[i]:
                    return False
            else:
                if words[i] in hashmap:
                    return False
                hashmap[index] = words[i]

        return True