class Solution:
    def longestPalindrome(self, s: str) -> str:
        sLen = len(s)
        start = 0
        maxLen = 0

        for i in range(sLen):
            for j in range(2):
                left = i
                right = i + j

                while left >= 0 and right < sLen and s[left] == s[right]:
                    left -= 1
                    right += 1

                curLen = right - left - 1
                if curLen > maxLen:
                    maxLen = curLen
                    start = left + 1

        return s[start : start + maxLen]
