from typing import List


class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()

        result = list()
        spellsSize = len(spells)
        potionsSize = len(potions)

        for i in range(spellsSize):
            left = 0
            right = potionsSize

            while left < right:
                mid = (left + right) // 2

                if spells[i] * potions[mid] < success:
                    left = mid + 1
                else:
                    right = mid

            result.append(potionsSize - left)

        return result


class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()

        spellsSize = len(spells)
        potionsSize = len(potions)

        for i in range(spellsSize):
            left = 0
            right = potionsSize

            while left < right:
                mid = (left + right) // 2

                if spells[i] * potions[mid] < success:
                    left = mid + 1
                else:
                    right = mid

            spells[i] = potionsSize - left

        return spells
