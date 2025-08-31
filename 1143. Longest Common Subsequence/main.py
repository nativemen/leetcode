class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1 = len(text1)
        len2 = len(text2)
        dp = [[0 for _ in range(len2)] for _ in range(len1)]

        for i in range(len1):
            for j in range(len2):
                if text1[i] == text2[j]:
                    dp[i][j] = 1 if i == 0 or j == 0 else dp[i - 1][j - 1] + 1
                else:
                    first = 0 if i == 0 else dp[i - 1][j]
                    second = 0 if j == 0 else dp[i][j - 1]
                    dp[i][j] = max(first, second)

        return dp[len1 - 1][len2 - 1]
