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
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        result = [[-1] * n for _ in range(m)]

        left = 0
        right = n - 1
        top = 0
        bottom = m - 1

        while left <= right and top <= bottom:
            for i in range(left, right + 1):
                if not head:
                    return result
                result[top][i] = head.val
                head = head.next
            top += 1

            for i in range(top, bottom + 1):
                if not head:
                    return result
                result[i][right] = head.val
                head = head.next
            right -= 1

            if top <= bottom:
                for i in range(right, left - 1, -1):
                    if not head:
                        return result
                    result[bottom][i] = head.val
                    head = head.next
                bottom -= 1

            if left <= right:
                for i in range(bottom, top - 1, -1):
                    if not head:
                        return result
                    result[i][left] = head.val
                    head = head.next
                left += 1

        return result


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        result = [[-1] * n for _ in range(m)]

        left = 0
        right = n - 1
        top = 0
        bottom = m - 1
        total = m * n
        count = 0

        while count < total:
            for i in range(left, right + 1):
                if not head:
                    return result
                result[top][i] = head.val
                head = head.next
                count += 1
            top += 1

            for i in range(top, bottom + 1):
                if not head:
                    return result
                result[i][right] = head.val
                head = head.next
                count += 1
            right -= 1

            if top <= bottom:
                for i in range(right, left - 1, -1):
                    if not head:
                        return result
                    result[bottom][i] = head.val
                    head = head.next
                    count += 1
                bottom -= 1

            if left <= right:
                for i in range(bottom, top - 1, -1):
                    if not head:
                        return result
                    result[i][left] = head.val
                    head = head.next
                    count += 1
                left += 1

        return result


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        result = [[-1] * n for _ in range(m)]

        left = 0
        right = n - 1
        top = 0
        bottom = m - 1
        total = m * n
        count = 0
        direction = 1

        while count < total:
            if direction == 1:
                for i in range(left, right + 1):
                    if not head:
                        return result
                    result[top][i] = head.val
                    head = head.next
                    count += 1
                top += 1
                direction = 2
            elif direction == 2:
                for i in range(top, bottom + 1):
                    if not head:
                        return result
                    result[i][right] = head.val
                    head = head.next
                    count += 1
                right -= 1
                direction = 3
            elif direction == 3:
                for i in range(right, left - 1, -1):
                    if not head:
                        return result
                    result[bottom][i] = head.val
                    head = head.next
                    count += 1
                bottom -= 1
                direction = 4
            else:
                for i in range(bottom, top - 1, -1):
                    if not head:
                        return result
                    result[i][left] = head.val
                    head = head.next
                    count += 1
                left += 1
                direction = 1

        return result


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        result = [[-1] * n for _ in range(m)]

        row = 0
        col = 0
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        direction = 0

        while head:
            result[row][col] = head.val

            nextRow = row + dirs[direction][0]
            nextCol = col + dirs[direction][1]

            if (
                nextRow < 0
                or nextRow >= m
                or nextCol < 0
                or nextCol >= n
                or result[nextRow][nextCol] != -1
            ):
                direction = (direction + 1) % 4
                nextRow = row + dirs[direction][0]
                nextCol = col + dirs[direction][1]

            row, col = nextRow, nextCol
            head = head.next

        return result
