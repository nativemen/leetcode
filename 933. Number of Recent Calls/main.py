class RecentCounter:
    def __init__(self):
        self.q = []

    def ping(self, t: int) -> int:
        self.q.append(t)

        while self.q[0] + 3000 < t:
            self.q.remove(self.q[0])

        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)

from collections import deque


class RecentCounter:
    def __init__(self):
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.append(t)

        while self.q[0] + 3000 < t:
            self.q.popleft()

        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)


class RecentCounter:
    def __init__(self):
        self.q = [0] * 10001
        self.head = 0
        self.tail = 0

    def ping(self, t: int) -> int:
        self.q[self.tail] = t
        self.tail += 1

        while self.q[self.head] + 3000 < t:
            self.head += 1

        return self.tail - self.head


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
