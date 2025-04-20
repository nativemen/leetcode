from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.array = list()
        self.index = 0

        def inorder(node: Optional[TreeNode], array: List[TreeNode]):
            if not node:
                return

            inorder(node.left, array)
            array.append(node)
            inorder(node.right, array)

        inorder(root, self.array)

    def next(self) -> int:
        if not self.hasNext():
            return -1

        value = self.array[self.index].val
        self.index += 1

        return value

    def hasNext(self) -> bool:
        return self.index < len(self.array)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.array = list()

        def inorder(node: Optional[TreeNode], array: List[TreeNode]):
            if not node:
                return

            inorder(node.left, array)
            array.append(node)
            inorder(node.right, array)

        inorder(root, self.array)

    def next(self) -> int:
        if not self.hasNext():
            return -1

        value = self.array[0].val
        self.array.remove(self.array[0])

        return value

    def hasNext(self) -> bool:
        return len(self.array) != 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
