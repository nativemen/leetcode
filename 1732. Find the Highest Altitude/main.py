from typing import List


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitude = 0
        largest = 0

        for val in gain:
            altitude += val
            largest = max(largest, altitude)

        return largest


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitudes = [0]

        for i in range(1, len(gain) + 1):
            altitudes.append(altitudes[i - 1] + gain[i - 1])

        return max(altitudes)
