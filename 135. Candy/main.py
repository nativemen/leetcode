from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        size = len(ratings)
        candy = [1] * size

        for i in range(1, size):
            if ratings[i] > ratings[i - 1]:
                candy[i] = candy[i - 1] + 1

        sum = candy[size - 1]

        for i in range(size - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                if candy[i] <= candy[i + 1]:
                    candy[i] = candy[i + 1] + 1

            sum += candy[i]

        return sum


class Solution:
    def candy(self, ratings: List[int]) -> int:
        size = len(ratings)
        candy = [1] * size

        for i in range(1, size):
            if ratings[i] > ratings[i - 1]:
                candy[i] = candy[i - 1] + 1

        for i in range(size - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candy[i] = max(candy[i], candy[i + 1] + 1)

        return sum(candy)
