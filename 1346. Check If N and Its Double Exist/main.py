class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        checked_set = set()
        for element in arr:
            if element * 2 in checked_set or element / 2 in checked_set:
                return True
            checked_set.add(element)

        return False
