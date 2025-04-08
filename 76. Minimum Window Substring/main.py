import sys
from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tMap = defaultdict(int)

        for c in t:
            tMap[c] += 1

        left = 0
        right = 0
        minLeft = 0
        minLen = sys.maxsize
        sLen = len(s)
        tLen = len(t)
        matched = 0
        sMap = defaultdict(int)

        for right in range(sLen):
            if s[right] not in tMap:
                continue

            sMap[s[right]] += 1
            if sMap[s[right]] <= tMap[s[right]]:
                matched += 1

            if matched == tLen:
                while s[left] not in tMap or sMap[s[left]] > tMap[s[left]]:
                    if s[left] in tMap:
                        sMap[s[left]] -= 1

                    left += 1

                size = right - left + 1
                if size < minLen:
                    minLen = size
                    minLeft = left

        if minLen == sys.maxsize:
            return ""

        return s[minLeft : minLeft + minLen]


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ARRAY_SIZE = 128
        count = [0] * ARRAY_SIZE

        for c in t:
            count[ord(c)] += 1

        left = 0
        right = 0
        minLeft = 0
        minLen = sys.maxsize
        matched = 0
        sLen = len(s)
        tLen = len(t)

        for right in range(sLen):
            if count[ord(s[right])] > 0:
                matched += 1

            count[ord(s[right])] -= 1

            while matched == tLen:
                size = right - left + 1
                if size < minLen:
                    minLen = size
                    minLeft = left

                count[ord(s[left])] += 1
                if count[ord(s[left])] > 0:
                    matched -= 1

                left += 1

        if minLen == sys.maxsize:
            return ""

        return s[minLeft : minLeft + minLen]


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ARRAY_SIZE = 128
        count = [0] * ARRAY_SIZE

        for c in t:
            count[ord(c)] += 1

        left = 0
        right = 0
        minLeft = 0
        minLen = sys.maxsize
        needed = len(t)
        sLen = len(s)

        while left < sLen:
            if right >= sLen and needed > 0:
                break

            if needed > 0:
                if count[ord(s[right])] > 0:
                    needed -= 1

                count[ord(s[right])] -= 1
                right += 1
            else:
                size = right - left
                if size < minLen:
                    minLen = size
                    minLeft = left

                count[ord(s[left])] += 1
                if count[ord(s[left])] > 0:
                    needed += 1

                left += 1

        if minLen == sys.maxsize:
            return ""

        return s[minLeft : minLeft + minLen]
