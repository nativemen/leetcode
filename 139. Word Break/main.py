from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        sLen = len(s)
        wordDictSize = len(wordDict)
        dp = [False] * (sLen + 1)
        dp[0] = True

        for i in range(sLen + 1):
            if not dp[i]:
                continue

            for j in range(wordDictSize):
                wordLen = len(wordDict[j])
                if s[i : i + wordLen] == wordDict[j]:
                    dp[i + wordLen] = True

        return dp[sLen]
