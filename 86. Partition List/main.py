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
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dummy1 = ListNode()
        dummy2 = ListNode()
        first = dummy1
        second = dummy2

        while head:
            if head.val < x:
                first.next = head
                first = first.next
            else:
                second.next = head
                second = second.next

            head = head.next

        first.next = dummy2.next
        second.next = None

        return dummy1.next


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dummy1 = ListNode(next=head)
        dummy2 = ListNode()
        first = dummy1
        second = dummy2

        while first.next:
            if first.next.val < x:
                first = first.next
            else:
                second.next = first.next
                second = second.next
                first.next = first.next.next

            head = head.next

        first.next = dummy2.next
        second.next = None

        return dummy1.next
