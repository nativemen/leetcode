import bisect
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        while left < right:
            sum = numbers[left] + numbers[right]
            if sum < target:
                left += 1
            elif sum > target:
                right -= 1
            else:
                break

        return [left + 1, right + 1]


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for first in range(len(numbers)):
            object = target - numbers[first]
            found = bisect.bisect_left(numbers[first + 1 :], object)
            if (
                found != len(numbers[first + 1 :])
                and numbers[first + 1 :][found] == object
            ):
                return [first + 1, found + first + 2]

        return [-1, -1]
