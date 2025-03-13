from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = defaultdict(int)
        size = len(s)
        result = 0
        left = 0

        for i in range(size):
            count[s[i]] += 1

            while count[s[i]] > 1:
                count[s[left]] -= 1
                left += 1

            result = max(result, i - left + 1)

        return result


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        left = 0
        size = len(s)

        for right in range(size):
            for start in range(left, right):
                if s[start] == s[right]:
                    left = start + 1
                    break

            result = max(result, right - left + 1)

        return result


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        left = 0
        seen = set()

        for right in range(len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left += 1
            seen.add(s[right])
            result = max(result, right - left + 1)

        return result


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        left = 0
        seen = dict()

        for right in range(len(s)):
            if s[right] in seen:
                if seen[s[right]] >= left:
                    left = seen[s[right]] + 1
            seen[s[right]] = right
            result = max(result, right - left + 1)

        return result