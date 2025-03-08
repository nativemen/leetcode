from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        size = len(height)
        left = 0
        right = size - 1
        left_max = 0
        right_max = 0
        total = 0

        while left <= right:
            if height[left] <= height[right]:
                if height[left] <= left_max:
                    total += left_max - height[left]
                else:
                    left_max = height[left]

                left += 1
            else:
                if height[right] <= right_max:
                    total += right_max - height[right]
                else:
                    right_max = height[right]

                right -= 1

        return total


class Solution:
    def trap(self, height: List[int]) -> int:
        size = len(height)
        prefix_max = [0] * size

        for i in range(1, size):
            prefix_max[i] = max(prefix_max[i - 1], height[i - 1])

        suffix_max = [0] * size

        for i in range(size - 2, -1, -1):
            suffix_max[i] = max(suffix_max[i + 1], height[i + 1])

        total = 0

        for i in range(size):
            top = min(prefix_max[i], suffix_max[i])
            if top >= height[i]:
                total += top - height[i]

        return total
