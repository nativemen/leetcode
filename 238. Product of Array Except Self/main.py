from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        prefix = [1] * size
        suffix = [1] * size

        for i in range(1, size):
            prefix[i] = prefix[i - 1] * nums[i - 1]

        for i in range(size - 2, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i + 1]

        answer = [1] * size
        for i in range(size):
            answer[i] = prefix[i] * suffix[i]

        return answer


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        answer = [1] * size

        prefix = 1
        for i in range(size):
            answer[i] = prefix
            prefix *= nums[i]

        suffix = 1
        for i in range(size - 1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]

        return answer
