import sys
from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_product = -sys.maxsize - 1
        left_product = 1
        right_product = 1
        size = len(nums)

        for i in range(0, size):
            left_product *= nums[i]
            right_product *= nums[size - 1 - i]
            max_product = max(max_product, left_product)
            max_product = max(max_product, right_product)
            if left_product == 0:
                left_product = 1
            if right_product == 0:
                right_product = 1

        return max_product


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_product = -sys.maxsize - 1
        cur_max = 1
        cur_min = 1

        for num in nums:
            temp = cur_max * num
            cur_max = max(temp, cur_min * num, num)
            cur_min = min(temp, cur_min * num, num)
            max_product = max(max_product, cur_max)

        return max_product
