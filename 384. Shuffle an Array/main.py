import random
from typing import List


class Solution:
    def __init__(self, nums: List[int]):
        self.orig = nums.copy()

    def reset(self) -> List[int]:
        return self.orig.copy()

    def shuffle(self) -> List[int]:
        shuf = self.orig.copy()
        random.shuffle(shuf)
        return shuf


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()


class Solution:
    def __init__(self, nums: List[int]):
        self.orig = nums.copy()

    def reset(self) -> List[int]:
        return self.orig.copy()

    def shuffle(self) -> List[int]:
        shuf = self.orig.copy()
        size = len(shuf)
        for i in range(size):
            swap = random.randrange(i, size)
            shuf[i], shuf[swap] = shuf[swap], shuf[i]
        return shuf


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
