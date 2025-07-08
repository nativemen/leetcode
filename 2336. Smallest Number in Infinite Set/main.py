import heapq


class SmallestInfiniteSet:
    def __init__(self):
        self.set = set()
        self.heap = []
        self.smallest = 1

    def popSmallest(self) -> int:
        if not self.heap:
            result = self.smallest
            self.smallest += 1
            return result

        result = heapq.heappop(self.heap)
        self.set.remove(result)

        return result

    def addBack(self, num: int) -> None:
        if num >= self.smallest:
            return

        if num not in self.set:
            self.set.add(num)
            heapq.heappush(self.heap, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)


class SmallestInfiniteSet:
    def __init__(self):
        self.heap = [i for i in range(1, 1001)]

    def popSmallest(self) -> int:
        return heapq.heappop(self.heap)

    def addBack(self, num: int) -> None:
        if num not in self.heap:
            heapq.heappush(self.heap, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)


class SmallestInfiniteSet:
    def __init__(self):
        self.nums = [True for _ in range(1002)]
        self.smallest = 1

    def popSmallest(self) -> int:
        smallest = self.smallest
        self.nums[self.smallest] = False

        for i in range(self.smallest + 1, 1002):
            if self.nums[i]:
                self.smallest = i
                break

        return smallest

    def addBack(self, num: int) -> None:
        self.nums[num] = True

        if num < self.smallest:
            self.smallest = num


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
