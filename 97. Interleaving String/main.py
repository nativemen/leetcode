from functools import lru_cache


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1Len = len(s1)
        s2Len = len(s2)
        s3Len = len(s3)

        if s1Len + s2Len != s3Len:
            return False

        dp = [[-1 for _ in range(s2Len + 1)] for _ in range(s1Len + 1)]

        def checkInterleave(s1: str, s2: str, s3: str, i: int, j: int, k: int) -> bool:
            nonlocal dp

            if i == s1Len and j == s2Len and k == s3Len:
                return True

            if k == s3Len:
                return False

            if dp[i][j] != -1:
                return dp[i][j] == 1

            cond1 = False
            cond2 = False

            if i < s1Len and k < s3Len and s1[i] == s3[k]:
                dp[i][j] = checkInterleave(s1, s2, s3, i + 1, j, k + 1)
                cond1 = dp[i][j]

            if j < s2Len and k < s3Len and s2[j] == s3[k]:
                dp[i][j] = checkInterleave(s1, s2, s3, i, j + 1, k + 1)
                cond2 = dp[i][j]

            return cond1 or cond2

        return checkInterleave(s1, s2, s3, 0, 0, 0)


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1Len = len(s1)
        s2Len = len(s2)
        s3Len = len(s3)

        if s1Len + s2Len != s3Len:
            return False

        dp = [[False for _ in range(s2Len + 1)] for _ in range(s1Len + 1)]
        dp[0][0] = True

        for i in range(s1Len + 1):
            for j in range(s2Len + 1):
                if i == 0 and j > 0:
                    dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]
                elif j == 0 and i > 0:
                    dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]
                elif i > 0 and j > 0:
                    dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or (
                        dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
                    )

        return dp[s1Len][s2Len]


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1Len = len(s1)
        s2Len = len(s2)
        s3Len = len(s3)

        if s1Len + s2Len != s3Len:
            return False

        dp = [[False for _ in range(s2Len + 1)] for _ in range(s1Len + 1)]
        dp[0][0] = True

        for i in range(s1Len + 1):
            for j in range(s2Len + 1):
                if i > 0 and s1[i - 1] == s3[i + j - 1]:
                    dp[i][j] = dp[i][j] or dp[i - 1][j]

                if j > 0 and s2[j - 1] == s3[i + j - 1]:
                    dp[i][j] = dp[i][j] or dp[i][j - 1]

        return dp[s1Len][s2Len]



class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1Len = len(s1)
        s2Len = len(s2)
        s3Len = len(s3)

        if s1Len + s2Len != s3Len:
            return False

        dp = [False for _ in range(s2Len + 1)]
        dp[0] = True

        for i in range(s1Len + 1):
            for j in range(s2Len + 1):
                if i == 0 and j > 0:
                    dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1]
                elif j == 0 and i > 0:
                    dp[0] = dp[0] and s1[i - 1] == s3[i - 1]
                elif i > 0 and j > 0:
                    dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or (
                        dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                    )

        return dp[s2Len]


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1Len = len(s1)
        s2Len = len(s2)
        s3Len = len(s3)

        if s1Len + s2Len != s3Len:
            return False

        @lru_cache(None)
        def dp(i: int, j: int) -> bool:
            if i == s1Len and j == s2Len:
                return True

            if i < s1Len and s1[i] == s3[i + j] and dp(i + 1, j):
                return True

            if j < s2Len and s2[j] == s3[i + j] and dp(i, j + 1):
                return True

            return False

        return dp(0, 0)