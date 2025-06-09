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
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head
        count = 0

        while fast and fast.next:
            count += 1
            slow = slow.next
            fast = fast.next.next

        prev = None

        while slow:
            next = slow.next
            slow.next = prev
            prev = slow
            slow = next

        node1 = head
        node2 = prev
        maxSum = 0

        for i in range(count):
            sum = node1.val + node2.val
            maxSum = max(maxSum, sum)
            node1 = node1.next
            node2 = node2.next

        return maxSum


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        node = head
        array = []

        while node:
            array.append(node.val)
            node = node.next

        left = 0
        right = len(array) - 1
        maxSum = 0

        while left < right:
            sum = array[left] + array[right]
            maxSum = max(maxSum, sum)
            left += 1
            right -= 1

        return maxSum


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None

        while slow:
            next = slow.next
            slow.next = prev
            prev = slow
            slow = next

        node1, node2 = head, prev
        maxSum = 0

        while node2:
            maxSum = max(maxSum, node1.val + node2.val)
            node1 = node1.next
            node2 = node2.next

        return maxSum
