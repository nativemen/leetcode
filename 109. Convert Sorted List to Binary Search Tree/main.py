from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        nums = list()

        while head is not None:
            nums.append(head.val)
            head = head.next

        return self.helper(nums, 0, len(nums) - 1)

    def helper(self, nums: list[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None

        mid = (left + right + 1) // 2
        node = TreeNode(nums[mid])
        node.left = self.helper(nums, left, mid - 1)
        node.right = self.helper(nums, mid + 1, right)

        return node


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        nums = list()

        while head is not None:
            nums.append(head.val)
            head = head.next

        return self.helper(nums)

    def helper(self, nums: list[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = len(nums) // 2
        node = TreeNode(nums[mid])
        node.left = self.helper(nums[:mid])
        node.right = self.helper(nums[mid + 1 :])

        return node


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        return self.helper(head, None)

    def findListMiddle(
        self, head: Optional[ListNode], tail: Optional[ListNode]
    ) -> Optional[ListNode]:
        slow = head
        fast = head

        while fast != tail and fast.next != tail:
            slow = slow.next
            fast = fast.next.next

        return slow

    def helper(
        self, head: Optional[ListNode], tail: Optional[ListNode]
    ) -> Optional[TreeNode]:
        if head == tail:
            return None

        mid = self.findListMiddle(head, tail)
        node = TreeNode(mid.val)
        if head == mid:
            return node

        node.left = self.helper(head, mid)
        node.right = self.helper(mid.next, tail)

        return node


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if head is None:
            return None

        mid = self.splitListAtMiddle(head)
        node = TreeNode(mid.val)
        if head == mid:
            return node
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(mid.next)

        return node

    def splitListAtMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head
        prev = None

        while fast is not None and fast.next is not None:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        if prev is not None:
            prev.next = None

        return slow
