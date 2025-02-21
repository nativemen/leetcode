from typing import List


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ARRAY_SIZE = 16
        MAX_COUNT = 1 << ARRAY_SIZE
        exists = [False] * MAX_COUNT

        for num in nums:
            index = int(num, 2)
            exists[index] = True

        val = 0
        while val < MAX_COUNT:
            if not exists[val]:
                break
            val += 1

        return bin(val)[2:].zfill(len(nums))


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ARRAY_SIZE = 16
        MAX_COUNT = 1 << ARRAY_SIZE
        exists = [False] * MAX_COUNT

        for num in nums:
            index = int(num, 2)
            exists[index] = True

        val = 0
        while val < MAX_COUNT:
            if not exists[val]:
                break
            val += 1

        return f"{val:0{len(nums)}b}"


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ARRAY_SIZE = 16
        MAX_COUNT = 1 << ARRAY_SIZE
        exists = [False] * MAX_COUNT

        for num in nums:
            index = int(num, 2)
            exists[index] = True

        val = 0
        while val < MAX_COUNT:
            if not exists[val]:
                break
            val += 1

        print(val)
        res = ""
        size = len(nums)
        for i in range(size - 1, -1, -1):
            res += chr(((val >> i) & 1) + ord("0"))

        return res


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = ""

        for i in range(len(nums)):
            if nums[i][i] == "0":
                res += "1"
            else:
                res += "0"

        return res


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = list()

        for i in range(len(nums)):
            if nums[i][i] == "0":
                res.append("1")
            else:
                res.append("0")

        return "".join(res)
