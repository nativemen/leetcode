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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeTwoLists(
            list1: Optional[ListNode], list2: Optional[ListNode]
        ) -> Optional[ListNode]:
            if list1 is None:
                return list2

            if list2 is None:
                return list1

            if list1.val < list2.val:
                list1.next = mergeTwoLists(list1.next, list2)
                return list1
            else:
                list2.next = mergeTwoLists(list1, list2.next)
                return list2

        size = len(lists)
        if size < 1:
            return None

        if size == 1:
            return lists[0]

        lists[1] = mergeTwoLists(lists[0], lists[1])
        lists.remove(lists[0])

        return self.mergeKLists(lists)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeTwoLists(
            list1: Optional[ListNode], list2: Optional[ListNode]
        ) -> Optional[ListNode]:
            dummy = ListNode()
            current = dummy

            while list1 is not None and list2 is not None:
                if list1.val < list2.val:
                    current.next = list1
                    list1 = list1.next
                else:
                    current.next = list2
                    list2 = list2.next

                current = current.next

            current.next = list1 if list1 is not None else list2

            return dummy.next

        size = len(lists)
        if size < 1:
            return None

        if size == 1:
            return lists[0]

        lists[1] = mergeTwoLists(lists[0], lists[1])
        lists.remove(lists[0])

        return self.mergeKLists(lists)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        current = dummy

        while list1 is not None and list2 is not None:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next

            current = current.next

        current.next = list1 if list1 is not None else list2

        return dummy.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        size = len(lists)
        if size < 1:
            return None

        if size == 1:
            return lists[0]

        lists[1] = self.mergeTwoLists(lists[0], lists[1])
        lists.remove(lists[0])

        return self.mergeKLists(lists)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        current = dummy

        while list1 is not None and list2 is not None:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next

            current = current.next

        current.next = list1 if list1 is not None else list2

        return dummy.next

    def mergeKListsHelper(
        self, lists: List[Optional[ListNode]], left: int, right: int
    ) -> Optional[ListNode]:
        if left > right:
            return None

        if left == right:
            return lists[left]

        mid = (left + right) // 2
        leftList = self.mergeKListsHelper(lists, left, mid)
        rightList = self.mergeKListsHelper(lists, mid + 1, right)

        return self.mergeTwoLists(leftList, rightList)

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        return self.mergeKListsHelper(lists, 0, len(lists) - 1)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        nodes = list()

        for lst in lists:
            node = lst
            while node:
                nodes.append(node)
                node = node.next

        nodes.sort(key=lambda x: x.val)

        size = len(nodes)
        for i in range(size - 1):
            nodes[i].next = nodes[i + 1]

        if size <= 0:
            return None

        nodes[size - 1].next = None
        return nodes[0]
