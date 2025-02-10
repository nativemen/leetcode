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
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        if fast is not None:
            slow = slow.next

        prev = None
        cur = slow
        while cur is not None:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp

        while prev is not None:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next

        return True


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        prev = None

        while fast is not None and fast.next is not None:
            fast = fast.next.next
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp

        if fast is not None:
            slow = slow.next

        while prev is not None:
            if prev.val != slow.val:
                return False
            prev = prev.next
            slow = slow.next

        return True


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        values = []

        while head is not None:
            values.append(head.val)
            head = head.next

        left = 0
        right = len(values) - 1
        while left < right:
            if values[left] != values[right]:
                return False
            left = left + 1
            right = right - 1

        return True


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        values = []

        while head is not None:
            values.append(head.val)
            head = head.next

        return values == values[::-1]


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def findSecondList(self, list: Optional[ListNode]) -> ListNode:
        slow = list
        fast = list

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        if fast is not None:
            slow = slow.next

        return slow

    def reverseList(self, list: Optional[ListNode]) -> ListNode:
        prev = None
        cur = list
        while cur is not None:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp

        return prev

    def compareLists(
        self, firstList: Optional[ListNode], secondList: Optional[ListNode]
    ) -> bool:
        while secondList is not None:
            if secondList.val != firstList.val:
                return False
            secondList = secondList.next
            firstList = firstList.next

        return True

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        secondList = self.findSecondList(head)
        secondHead = self.reverseList(secondList)

        return self.compareLists(head, secondHead)
