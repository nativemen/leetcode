from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()

        numsSize = len(nums)
        if numsSize % 2 != 0:
            return nums[numsSize // 2]
        else:
            return (nums[numsSize // 2 - 1] + nums[numsSize // 2]) / 2.0


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1Size = len(nums1)
        nums2Size = len(nums2)
        numsSize = nums1Size + nums2Size
        i = 0
        j = 0
        m1 = 0
        m2 = 0

        for count in range(numsSize // 2 + 1):
            m1 = m2

            if i == nums1Size:
                m2 = nums2[j]
                j += 1
            elif j == nums2Size:
                m2 = nums1[i]
                i += 1
            elif nums1[i] < nums2[j]:
                m2 = nums1[i]
                i += 1
            else:
                m2 = nums2[j]
                j += 1

        if numsSize % 2 != 0:
            return m2
        else:
            return (m1 + m2) / 2.0
