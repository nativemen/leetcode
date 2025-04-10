import bisect
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        maxLen = 1
        numsSize = len(nums)
        dp = [1] * (numsSize + 1)

        for i in range(numsSize):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    maxLen = max(maxLen, dp[i])

        return maxLen


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        numsSize = len(nums)
        dp = [1] * (numsSize + 1)

        for i in range(numsSize):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        numsSize = len(nums)
        dp = [1] * (numsSize + 1)

        for i in range(numsSize - 1, -1, -1):
            for j in range(i, numsSize):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)


class Solution:
    def binarySearch(self, seq: List[int], target: int) -> int:
        left = 0
        right = len(seq) - 1

        while left <= right:
            mid = (left + right) // 2

            if seq[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left

    def lengthOfLIS(self, nums: List[int]) -> int:
        numsSize = len(nums)

        if numsSize == 0:
            return 0

        seq = list()
        seq.append(nums[0])

        for num in nums:
            if seq[-1] < num:
                seq.append(num)
            else:
                index = self.binarySearch(seq, num)
                seq[index] = num

        return len(seq)


class Solution:
    def binarySearch(self, seq: List[int], len: int, target: int) -> int:
        left = 0
        right = len - 1

        while left <= right:
            mid = (left + right) // 2

            if seq[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left

    def lengthOfLIS(self, nums: List[int]) -> int:
        len = 0

        for num in nums:
            if len == 0 or nums[len - 1] < num:
                nums[len] = num
                len += 1
            else:
                index = self.binarySearch(nums, len, num)
                nums[index] = num

        return len


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        numsSize = len(nums)

        if numsSize == 0:
            return 0

        seq = list()
        seq.append(nums[0])

        for num in nums:
            if seq[-1] < num:
                seq.append(num)
            else:
                index = bisect.bisect_left(seq, num)
                seq[index] = num

        return len(seq)
