from collections import Counter
from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        len1 = len(nums1)
        len2 = len(nums2)
        result = []
        i = 0
        j = 0

        while i < len1 and j < len2:
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                result.append(nums1[i])
                i += 1
                j += 1

        return result


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        count1 = Counter(nums1)
        count2 = Counter(nums2)

        result = list()
        for key in count1:
            count = min(count1[key], count2[key])
            for _ in range(count):
                result.append(key)

        return result


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        count1 = Counter(nums1)

        result = list()
        for num in nums2:
            if num in count1:
                result.append(num)
                count1[num] -= 1
                if count1[num] == 0:
                    del count1[num]

        return result
