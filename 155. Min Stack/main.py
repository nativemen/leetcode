class MinStack:

    def __init__(self):
        self.val_stack = []
        self.min_stack = []
        self.max_size = 30000

    def push(self, val: int) -> None:
        if len(self.val_stack) > self.max_size:
            raise IndexError("Stack is full.")

        if len(self.val_stack) == 0:
            self.min_stack.append(val)
        else:
            self.min_stack.append(min(val, self.min_stack[-1]))

        self.val_stack.append(val)

    def pop(self) -> None:
        if len(self.val_stack) == 0:
            raise IndexError("Stack is empty.")

        self.val_stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        if len(self.val_stack) == 0:
            raise IndexError("Stack is empty.")

        return self.val_stack[-1]

    def getMin(self) -> int:
        if len(self.val_stack) == 0:
            raise IndexError("Stack is empty.")

        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()


class MinStack:

    def __init__(self):
        self.stack = []
        self.max_size = 30000

    def push(self, val: int) -> None:
        if len(self.stack) > self.max_size:
            raise IndexError("Stack is full.")

        if len(self.stack) == 0:
            self.stack.append((val, val))
        else:
            self.stack.append((val, min(val, self.stack[-1][1])))


    def pop(self) -> None:
        if len(self.stack) == 0:
            raise IndexError("Stack is empty.")

        self.stack.pop()

    def top(self) -> int:
        if len(self.stack) == 0:
            raise IndexError("Stack is empty.")

        return self.stack[-1][0]

    def getMin(self) -> int:
        if len(self.stack) == 0:
            raise IndexError("Stack is empty.")

        return self.stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()