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
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head

        count = 1
        node = head

        while node.next:
            node = node.next
            count += 1

        node.next = head
        offset = count - (k % count)
        node = head

        for i in range(1, offset):
            node = node.next

        head = node.next
        node.next = None

        return head
