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
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        head1 = l1
        head2 = l2
        carry = 0

        while head1 is not None or head2 is not None:
            sum = carry

            if head1 is not None:
                sum += head1.val

            if head2 is not None:
                sum += head2.val

            carry = sum // 10
            if head1 is not None:
                head1.val = sum % 10
                if head1.next is None and head2 is None:
                    if carry != 0:
                        head1.next = ListNode(carry)
                    return l1
                head1 = head1.next

            if head2 is not None:
                head2.val = sum % 10
                if head1 is None and head2.next is None:
                    if carry != 0:
                        head2.next = ListNode(carry)
                    return l2
                head2 = head2.next

        return l1


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        head1 = l1
        head2 = l2
        carry = 0

        while head1 or head2:
            sum = carry

            if head1:
                sum += head1.val

            if head2:
                sum += head2.val

            carry = sum // 10
            if head1:
                head1.val = sum % 10
                if not head1.next and not head2:
                    if carry != 0:
                        head1.next = ListNode(carry)
                    return l1
                head1 = head1.next

            if head2:
                head2.val = sum % 10
                if not head1 and not head2.next:
                    if carry != 0:
                        head2.next = ListNode(carry)
                    return l2
                head2 = head2.next

        return l1


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummyNode = ListNode()
        currentNode = dummyNode
        carry = 0

        while l1 or l2 or carry:
            sum = carry

            if l1:
                sum += l1.val

            if l2:
                sum += l2.val

            carry = sum // 10
            currentNode.next = ListNode(val=sum % 10)
            currentNode = currentNode.next
            if l1:
                l1 = l1.next

            if l2:
                l2 = l2.next

        return dummyNode.next
