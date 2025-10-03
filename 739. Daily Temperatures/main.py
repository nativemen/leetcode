from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        tempSize = len(temperatures)

        result = [0] * tempSize
        stack = []

        for i in range(tempSize):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                index = stack.pop()
                result[index] = i - index

            stack.append(i)

        return result
