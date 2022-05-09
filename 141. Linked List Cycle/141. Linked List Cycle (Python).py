class node: #this is a single node object in a linked list
  def __init__(self, val = 0,next = None):
    self.val = val #val is the actual value held in the node
    self.next = next #next is a node object that points to the next node

      
def linkedlistcycle1(head): # My first solution. This uses O(n) space since it makes a copy of the linked list
  copy = set() #this is a python set, which acts as a hashtable for rapid constant time lookups
  curnode = head
  while curnode != None:
    if curnode in copy:
      return true
    else:
      copy.add(curnode)
      curnode = curnode.next
      continue
  return false
  
def linkedlistcycle2(head): # This is my second solution, that uses only O(1) space.
  # Both slow and fast initially point to same node 
  slow = fast = head 

  while slow and fast and fast.next: # just checks that slow, fast and fast.next are not None, to ensure no error arises
    # slow only goes up by 1 step
    slow = slow.next 

    # fast goes up by 2 steps
    fast = fast.next.next 

    # since fast goes up by 2 while slow only goes up by 1, if there is cycle, fast will ultimately catch up to slow and equal slow. This is used to indicate a cycle
    # if there is no cycle, fast would just reach None at the end of the linked list, which would break out of the while loop
    # Note the use of the is operator. This is because, I want to check that slow equals fast by reference (ie that they are the exact same object!). If I used the == sign operator, it would only check equivalence by value, which would not work, since there could coincidently be 2 nodes with same value (but different reference) in the list, without there being a loop
    if slow is fast:
      return True
    else:
      continue
   else:
      return False
  
