class MinStack:

    def __init__(self):
        self.stack = []
        self.min = float('inf')

    def push(self, val: int) -> None:
        self.stack.append(val)
        if val < self.min:
            self.min = val

    def pop(self) -> None:
        if self.min == self.stack.pop() :
            if self.stack:
                self.min = min(self.stack)
            else:
                self.min = float('inf')

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min

'''
class MinStack:

    def __init__(self):
        self._val_stack = []
        self._min_stack = []

    def push(self, val: int) -> None:
        self._val_stack.append(val)
        if not self._min_stack or val < self._min_stack[-1]:
            self._min_stack.append(val)
        else:
            self._min_stack.append(self._min_stack[-1])

    def pop(self) -> None:
        self._val_stack.pop()
        self._min_stack.pop()

    def top(self) -> int:
        return self._val_stack[-1]

    def getMin(self) -> int:
        return self._min_stack[-1]
'''

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()