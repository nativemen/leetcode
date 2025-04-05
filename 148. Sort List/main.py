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
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        array = list()
        node = head

        while node:
            array.append(node.val)
            node = node.next

        array.sort()
        node = head
        index = 0

        while node:
            node.val = array[index]
            index += 1
            node = node.next

        return head
