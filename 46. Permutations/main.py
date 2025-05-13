from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []

        if not nums:
            return result

        array = []

        def backtrack(nums: List[int]):
            if len(array) == len(nums):
                result.append(array.copy())
                return

            for num in nums:
                if array.count(num) == 0:
                    array.append(num)
                    backtrack(nums)
                    array.pop()

        backtrack(nums)

        return result


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []

        if not nums:
            return result

        array = []

        def backtrack(nums: List[int], visited: List[bool]):
            if len(array) == len(nums):
                result.append(array.copy())
                return

            for i in range(len(nums)):
                if visited[i]:
                    continue
                visited[i] = True
                array.append(nums[i])
                backtrack(nums, visited)
                array.pop()
                visited[i] = False

        backtrack(nums, [False] * len(nums))

        return result
