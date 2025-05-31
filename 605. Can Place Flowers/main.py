from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        def isEmpty(pos: int) -> bool:
            return pos < 0 or pos >= len(flowerbed) or flowerbed[pos] == 0

        count = 0

        for i in range(len(flowerbed)):
            if isEmpty(i - 1) and isEmpty(i) and isEmpty(i + 1):
                count += 1
                flowerbed[i] = 1

        return count >= n


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0

        for i in range(len(flowerbed)):
            left = i - 1 < 0 or flowerbed[i - 1] == 0
            right = i + 1 >= len(flowerbed) or flowerbed[i + 1] == 0

            if left and right and flowerbed[i] == 0:
                count += 1
                flowerbed[i] = 1

        return count >= n
