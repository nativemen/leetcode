import random


class RandomizedSet:

    def __init__(self):
        self.set = set()

    def insert(self, val: int) -> bool:
        if val in self.set:
            return False

        self.set.add(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.set:
            return False

        self.set.remove(val)
        return True

    def getRandom(self) -> int:
        if len(self.set) == 0:
            raise ValueError("set is empty!")

        return random.choice(list(self.set))


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()


import random


class RandomizedSet:

    def __init__(self):
        self.dict = dict()

    def insert(self, val: int) -> bool:
        if val in self.dict:
            return False

        self.dict[val] = 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.dict:
            return False

        self.dict.pop(val)
        return True

    def getRandom(self) -> int:
        if len(self.dict) == 0:
            raise ValueError("set is empty!")

        return random.choice(list(self.dict))


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
