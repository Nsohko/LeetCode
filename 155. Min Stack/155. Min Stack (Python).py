class MinStack:

    # my stack inplementation involves a list of these nodes. This node object is the object component of my stack
    class node:
      def __init__(self, val, curmin):
        # val is the value stored in the node
        self.val = val
        # curmin is equal to the minimum value of the node and all nodes below it in the stack. It is thus dependent on this node's value as well as all the nodes below it on the stack
        self.curmin = curmin

    def __init__(self):
      # this stack list is the stack that contains the nodes
      self.stack = []

    # pushes a new node with a specific value (val) to top of stack
    def push(self, val: int) -> None: # this ' -> None' syntax is just to provide documentation on the functions return value. It serves the same purpose as a comment.
      # calls the getMin function (defined later in the MinList class) to get the current minimum value of the list before adding the new node.
      # the current minimum of the list equals the curmin value of the current top node
      curmin = self.getMin()

      # there are 3 cases in the following if statement
      # case 1: curmin == None. From the getMin function, this occurs when stack is empty. Thus, newnode is only mode in stack, so curmin must equal it's own value 
      # case 2: val < curmin. Curmin equals the minimum value of the current top node and all nodes below it, which is equivalent to minimum value of the stack. If new val < curmin, then that means that once the new node is placed on top, the minimum value of newnode and all nodes below it will be newnode's val. Thus, newnodes curmin will equal its own val
      # case 3: else. If case 1 and case 2 don't happen, val > curmin. Thus, even after adding the newnode to the top of the stack, the minimum value of newbies and all nodes below it will still be the same as previous curmin
      if curmin == None or val < curmin:
        curmin = val
      newnode = self.node(val, curmin)
      self.stack.append(newnode)

    # deletes top node in the stack
    def pop(self) -> None:
      # just pops top node out. Once top node is popped, new top node will be the previously second node
      # the new minimum value of the stack equals the curmin value of the new top node, as this value equals the minimum of the new top node and all nodes below it, which is the entire new stack.
      self.stack.pop()
        
    # just returns value of top node of stack
    def top(self) -> int:
      # indexing at -1 refers to last node in the stack, which is the top node
      topval = self.stack[-1].val
      return topval
        
    # returns minimum value in stack
    def getMin(self) -> int:
      # checks for case where stack is empty
      if len(self.stack) == 0:
        return None
      else:
        # indexing at -1 gives the last node of the stack, which is the top node
        # the curmin of this node gives the minimum value of the node and all nodes below it. However, since this node also equals the top node, this will give us the minimum value of the full stack
        minval = self.stack[-1].curmin
        return minval
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
