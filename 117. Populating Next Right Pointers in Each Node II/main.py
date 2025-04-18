class Node:
    def __init__(
        self,
        val: int = 0,
        left: "Node" = None,
        right: "Node" = None,
        next: "Node" = None,
    ):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: "Node") -> "Node":
        if not root:
            return None

        queue = [root]

        while len(queue) != 0:
            size = len(queue)
            prev = None

            for i in range(size):
                node = queue.pop(0)

                if prev:
                    prev.next = node

                prev = node

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

        return root


"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def getNext(self, node: "Node") -> "Node":
        while node:
            if node.left:
                return node.left

            if node.right:
                return node.right

            node = node.next

        return None

    def connect(self, root: "Node") -> "Node":
        if not root:
            return None

        if root.left:
            if root.right:
                root.left.next = root.right
            else:
                root.left.next = self.getNext(root.next)

        if root.right:
            root.right.next = self.getNext(root.next)

        self.connect(root.right)
        self.connect(root.left)

        return root


"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: "Node") -> "Node":
        if not root:
            return None

        node = root

        while node:
            leftestNode = None
            nextNode = None

            while node:
                if node.left:
                    if not leftestNode:
                        nextNode = node.left
                        leftestNode = nextNode
                    else:
                        nextNode.next = node.left
                        nextNode = nextNode.next

                if node.right:
                    if not leftestNode:
                        nextNode = node.right
                        leftestNode = nextNode
                    else:
                        nextNode.next = node.right
                        nextNode = nextNode.next

                node = node.next

            node = leftestNode

        return root
