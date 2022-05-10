class MinStack:

    class node:
      def __init__(self, val, curmin):
        self.val = val
        self.curmin = curmin

    def __init__(self):
      self.stack = []

    def push(self, val: int) -> None:
      curmin = self.getMin()
      if curmin == None or val < curmin:
        curmin = val
      newnode = self.node(val, curmin)
      self.stack.append(newnode)

    def pop(self) -> None:
      self.stack.pop()
        

    def top(self) -> int:
      topval = self.stack[-1].val
      return topval
        

    def getMin(self) -> int:
      if len(self.stack) == 0:
        return None
      else:
        minval = self.stack[-1].curmin
        return minval
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
