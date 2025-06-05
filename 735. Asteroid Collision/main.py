from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []
        i = 0
        asteroidsSize = len(asteroids)

        while i < asteroidsSize:
            if not result or result[-1] < 0 or asteroids[i] >= 0:
                result.append(asteroids[i])
                i += 1
            elif result[-1] + asteroids[i] < 0:
                result.pop()
            elif result[-1] + asteroids[i] == 0:
                result.pop()
                i += 1
            else:
                i += 1

        return result
