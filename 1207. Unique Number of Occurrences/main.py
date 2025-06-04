from collections import defaultdict
from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        maps = defaultdict(int)

        for num in arr:
            maps[num] += 1

        sets = set()

        for val in maps.values():
            if val in sets:
                return False

            sets.add(val)

        return True
