from collections import OrderedDict, defaultdict


class LRUCache:
    def __init__(self, capacity: int):
        ARRAY_SIZE = 10001
        self.cap = capacity
        self.count = 0
        self.que = list()
        self.values = [-1] * ARRAY_SIZE
        self.freq = [0] * ARRAY_SIZE

    def get(self, key: int) -> int:
        if self.count == 0:
            return -1

        if self.values[key] == -1:
            return -1

        self.que.append(key)
        self.freq[key] += 1

        return self.values[key]

    def put(self, key: int, value: int) -> None:
        if self.values[key] == -1:
            while self.count >= self.cap:
                delKey = self.que.pop(0)

                if self.freq[delKey] == 1:
                    self.values[delKey] = -1
                    self.count -= 1

                self.freq[delKey] -= 1

            self.freq[key] = 1
            self.count += 1
        else:
            self.freq[key] += 1

        self.values[key] = value
        self.que.append(key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.val = value
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.maps = defaultdict(Node)

    def delNode(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def addNode(self, node: Node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        if len(self.maps) == 0:
            return -1

        if key not in self.maps:
            return -1

        self.delNode(self.maps[key])
        self.addNode(self.maps[key])

        return self.maps[key].val

    def put(self, key: int, value: int) -> None:
        if key not in self.maps:
            if len(self.maps) >= self.cap:
                node = self.tail.prev
                self.delNode(node)
                del self.maps[node.key]

            self.maps[key] = Node(key, value)
            self.addNode(self.maps[key])
        else:
            self.maps[key].val = value
            self.delNode(self.maps[key])
            self.addNode(self.maps[key])


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        self.cache.move_to_end(key)

        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)

        self.cache[key] = value

        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
