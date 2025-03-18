from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        maps = defaultdict(list)

        for str in strs:
            word = "".join(sorted(str))
            maps[word].append(str)

        return list(maps.values())


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        maps = dict()

        for str in strs:
            word = "".join(sorted(str))
            if word in maps:
                maps[word].append(str)
            else:
                maps[word] = [str]

        return list(maps.values())
