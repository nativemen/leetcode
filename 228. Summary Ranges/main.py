from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = list()
        size =len(nums)
        i = 0

        while i < size:
            start = nums[i]

            while i + 1 < size and nums[i + 1] == nums[i] + 1:
                i += 1

            if start == nums[i]:
                result.append(str(start))
            else:
                result.append(str(start) + "->" + str(nums[i]))

            i += 1

        return result

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = list()
        size =len(nums)
        i = 0

        while i < size:
            start = nums[i]

            while i + 1 < size and nums[i + 1] == nums[i] + 1:
                i += 1

            if start == nums[i]:
                result.append(f"{start}")
            else:
                result.append(f"{start}" + "->" + f"{nums[i]}")

            i += 1

        return result