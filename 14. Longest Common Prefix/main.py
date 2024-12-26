from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = strs[0]
        prefixLen = len(strs[0])

        for i in range(1, len(strs)):
            j = 0
            length = len(strs[i])

            while j < prefixLen and j < length and strs[i][j] == s[j]:
                j += 1

            prefixLen = j
            if prefixLen == 0:
                break

        return s[:prefixLen]


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = strs[0]

        for str in strs[1:]:
            while not str.startswith(common):
                common = common[:-1]

        return common


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = strs[0]
        prefixLen = len(strs[0])

        for str in strs[1:]:
            while prefixLen > 0 and common[:prefixLen] != str[:prefixLen]:
                prefixLen -= 1

        return common[:prefixLen]
