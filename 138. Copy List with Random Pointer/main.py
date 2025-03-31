import copy
from collections import defaultdict
from typing import Optional


class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if not head:
            return None

        array = list()
        current = head
        count = 0

        while current:
            array.append(Node(current.val))
            count += 1
            current = current.next

        current = head
        index = 0

        while current:
            if current.next:
                array[index].next = array[index + 1]
            if current.random:
                idx = 0
                node = head
                while current.random != node:
                    node = node.next
                    idx += 1
                array[index].random = array[idx]

            current = current.next
            index += 1

        return array[0]


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if not head:
            return None

        maps = defaultdict(Optional[Node])

        current = head

        while current:
            maps[current] = Node(current.val)
            current = current.next

        current = head

        while current:
            if current.next:
                maps[current].next = maps[current.next]
            if current.random:
                maps[current].random = maps[current.random]
            current = current.next

        return maps[head]


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if not head:
            return None

        maps = defaultdict(Optional[Node])
        maps[None] = None
        current = head

        while current:
            maps[current] = Node(current.val)
            current = current.next

        current = head

        while current:
            maps[current].next = maps[current.next]
            maps[current].random = maps[current.random]
            current = current.next

        return maps[head]


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        return copy.deepcopy(head)


"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        current = head
        maps = defaultdict(Optional[Node])
        maps[None] = None

        while current:
            if current not in maps:
                maps[current] = Node(current.val)

            if current.next not in maps:
                maps[current.next] = Node(current.next.val)
            maps[current].next = maps[current.next]

            if current.random not in maps:
                maps[current.random] = Node(current.random.val)
            maps[current].random = maps[current.random]

            current = current.next

        return maps[head]
