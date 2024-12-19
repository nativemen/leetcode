from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        answer = 0

        for num in nums:
            answer ^= num

        return answer


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hashset = set()

        for num in nums:
            if num in hashset:
                hashset.remove(num)
            else:
                hashset.add(num)

        return hashset.pop()


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hashmap = dict()

        for num in nums:
            if num in hashmap:
                hashmap.pop(num)
            else:
                hashmap[num] = 1

        key, _ = hashmap.popitem()

        return key
