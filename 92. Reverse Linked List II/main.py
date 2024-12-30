from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        leftPrev = None
        leftNode = head

        for i in range(1, left):
            leftPrev = leftNode
            leftNode = leftNode.next

        prev = None
        current = leftNode
        next = None
        for i in range(left, right + 1):
            next = current.next
            current.next = prev
            prev = current
            current = next

        if leftPrev is None:
            head = prev
        else:
            leftPrev.next = prev
        leftNode.next = current

        return head


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        nodes = list()
        node = head

        while node is not None:
            nodes.append(node)
            node = node.next

        for i in range(left - 1, int((left + right) / 2)):
            temp = nodes[i]
            nodes[i] = nodes[left + right - 2 - i]
            nodes[left + right - 2 - i] = temp

        length = len(nodes)
        for i in range(length - 1):
            nodes[i].next = nodes[i + 1]

        nodes[length - 1].next = None

        return nodes[0]


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        values = list()
        node = head

        while node is not None:
            values.append(node.val)
            node = node.next

        for i in range(left - 1, int((left + right) / 2)):
            temp = values[i]
            values[i] = values[left + right - 2 - i]
            values[left + right - 2 - i] = temp

        length = len(values)
        node = head
        for i in range(length):
            node.val = values[i]
            node = node.next

        return head


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(
        self, leftNode: Optional[ListNode], rightNode: Optional[ListNode]
    ) -> Optional[ListNode]:
        prev = None
        current = leftNode
        next = None
        while current is not rightNode:
            next = current.next
            current.next = prev
            prev = current
            current = next

        current.next = prev

        return current

    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        leftPrev = None
        leftNode = head

        for i in range(1, left):
            leftPrev = leftNode
            leftNode = leftNode.next

        rightNode = None
        rightNext = leftNode

        for i in range(left, right + 1):
            rightNode = rightNext
            rightNext = rightNext.next
        if leftPrev is None:
            head = self.reverse(leftNode, rightNode)
        else:
            leftPrev.next = self.reverse(leftNode, rightNode)
        leftNode.next = rightNext

        return head
