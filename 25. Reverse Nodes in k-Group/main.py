from typing import List, Optional


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
    def reverse(self, values: List, left: int, right: int):
        while left < right:
            values[left], values[right] = values[right], values[left]
            left += 1
            right -= 1

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        values = list()
        node = head

        while node:
            values.append(node.val)
            node = node.next

        size = len(values)

        for i in range(0, size - k + 1, k):
            self.reverse(values, i, i + k - 1)

        node = head
        for i in range(size):
            node.val = values[i]
            node = node.next

        return head


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k <= 1:
            return head

        current = head

        for i in range(k):
            if not current:
                return head
            current = current.next

        current = head
        prev = None
        next = None
        count = 0

        while current and count < k:
            next = current.next
            current.next = prev
            prev = current
            current = next
            count += 1

        if next:
            head.next = self.reverseKGroup(next, k)

        return prev


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getKth(self, node: Optional[ListNode], k: int) -> Optional[ListNode]:
        while node and k > 0:
            node = node.next
            k -= 1

        return node

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            kth = self.getKth(groupPrev, k)
            if not kth:
                break

            groupNext = kth.next
            prev, current = kth.next, groupPrev.next
            while current != groupNext:
                next = current.next
                current.next = prev
                prev = current
                current = next

            groupPrev.next, groupPrev = kth, groupPrev.next

        return dummy.next
