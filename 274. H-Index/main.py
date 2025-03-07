from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        ARRAY_SIZE = 1001
        dp = [0] * (ARRAY_SIZE + 1)

        for citation in citations:
            dp[citation] += 1

        for i in range(ARRAY_SIZE - 1, -1, -1):
            dp[i] += dp[i + 1]
            if dp[i] >= i:
                return i

        return 0


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        citations.reverse()

        h = 0
        for i in range(len(citations)):
            if citations[i] < i + 1:
                break
            h = i + 1

        return h


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)

        h = 0
        for i in range(len(citations)):
            if citations[i] < i + 1:
                break
            h = i + 1

        return h
