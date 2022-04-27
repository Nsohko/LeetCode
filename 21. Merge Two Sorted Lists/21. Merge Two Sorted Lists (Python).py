class node: #this is a single node object in a linked list
  def __init__(self, val = 0,next = None):
    self.val = val #val is the actual value held in the node
    self.next = next #next is a node object that points to the next node

class linkedlist:
  def __init__(self, head = None):
    self.head = head #head is the head node object of the linked list
  def endinsert(self, val): #this function simply appends a new nodeto the end of the linked list
    newnode = node(val)
    if self.head == None: 
       self.head = newnode
    else:
      currnode = self.head
      while currnode.next != None: 
        currnode = currnode.next 
      currnode.next = newnode
 
# You cant say: while currnode!=None:
#                 currnode=currnode.next
#                 currnode=newnode
# This is because saying currnode=newnode simply reassigns currnode, rather thsn changing tge val of the obj initially pointed to by currnode. ie if currnodr=vurrnode.next then now currnode and currnode.next point to the same ibject. howevee, if i then write currnode=neenode, it just reassigns currnode to neenode rather than changing what currnode was initially assigned to. eg a=5, b=a, b=10. this code will not change the balue of a to 10. this is called pass bt object reference. basically when equating teo variables, python just copies the reference of the right side var ti the left side. for mutable obj, you can modify one variable (eg appending a list)and it will modify both but reassigning one variable will not affect tge other. for immutable obj, neitger modify nor reassignment will affect tge other. 
                   
    
  def initialise(self, vals): #initialises a linked list which contains the values in vals, where vals is a list
    for i in vals:
      self.endinsert(i)
      
  def insert(self, pos, val): #inserts a new node with value of val at a position of pos in the linked list
     newnode=node(val)
     if pos == 0:
       newnode.next = self.head
       self.head = newnode
     else:
       i = 0
       currnode = self.head
       while i < pos-1:
         currnode = currnode.next
         i += 1
       newnode.next = currnode.next
       currnode.next = newnode
     
  def printll(self): #prints out all values in a linked list
     curnode = self.head
     while curnode != None:
       print(curnode.val, end=' ')
       curnode = curnode.next
     print('')

def linkedlistmerger1(head1, head2):
  dummy = node()
  curout = dummy
  while head1 != None and head2 != None:
    if head1.val >= head2.val:
      curout.next = head2 #since this is a linked list, I can just do this, as it will essentially modify the node pointers as it goes to form the output list.Thid saves memeory space, making it O(1) memory conplexity. In comparison, creating a new node for each val (eg newnode=node(curnode2.val)) and then adding it to the output list(ie curout.next=newnode ) will give me O(n) space conmplexity since it will essentially create a new node for each value which takes up space
      curout = curout.next
      head2 = head2.next    
    elif head2.val > head1.val:
      curout.next = head1
      curout = curout.next
      head1 = head1.next  
  else:
    if head1 == None:
      curout.next = head2
    elif head2 == None:
      curout.next = head1
  return dummy.next 
#careful about this. Out was initialised as a dummy node. It has no value. The next node of the dummy node points to the true head node, with the actual value!
  
def linkedlistmerger2(head1, head2): #an alternative solution, but I think this is worse than the first solution
  if head1 == None:
    return head2
  elif head2 == None:
    return head1
  else:
    if head1.val >= head2.val:
      head2.next = recurslinkedlistmerge(head1,head2.next)
      return head2
    elif head2.val > head1.val:
      head1.next = recurslinkedlistmerge(head1.next,head2)
      return head1
    return head2
  if head2 == None:
    return head1
  if head1.val >= head2.val:
    seek = head2
    target = head1
  elif head2.val > head1.val:
    seek = head1
    target = head2
  headout = seek
  while seek != None and target != None:
    while seek.next != None and seek.next.val < target.val:
      seek = seek.next
    seek.next, target = target, seek.next
  return headout

#The following solution uses recursion, making it very fast. The function basically recursively places the next node every time it is called. 
#So it will recurisvely combine the lists every time and then shift the head from one list forward.
#Every time the function returns a node, it also returns all the values in the nodes after in the sorted merged list, which is what allows it to recursively solve. 
#So, it determines the node's next value in the sorted merged list first (all the way till the end of the merged sorted list). When one of the two initial lists hits its end, the function will set next next to just be the other list. After this,it returns the node and adds it to the next value of the original node that was being modified.
#If you don't understand my explanation, it's fine, the code is self explanatory.

def linkedlistmergerrecursive(head1, head2):
  if head1 == None:
    return head2
  elif head2 == None:
    return head1
  else:
    if head1.val >= head2.val:
      head2.next = linkedlistmergerrecursive(head1,head2.next)
      return head2
    elif head2.val > head1.val:
      head1.next = linkedlistmergerrecursive(head1.next,head2)
      return head1

def linkedlistnodeprinter(node): #just a simple function to print a linked list that originates from a particular node. Not part of solution
  while node != None:
    print(node.val, end=' ')
    node = node.next
  print('')

lt1=[3]
lt2=[4,5]

ll1 = linkedlist()
ll1.initialise(lt1) #initiliases a linked list called ll1 with the values in lt1
head1 = ll1.head

ll2 = linkedlist()
ll2.initialise(lt2) #initiliases a linked list called ll1 with the values in lt1
head2 = ll2.head

solnhead = linkedlistmergerrecursive(head1, head2)
#solnhead = linkedlistmerger1(head1, head2)
#solnhead = linkedlistmergerrecursive(head1, head2)

linkedlistnodeprinter(solnhead)

#NOTE: you cannot use any of the two programe successively with the same parameters in the same run of the programme.
#This is because each solution modifies the two of linked list parameters (head1 and head2) and essentially intertwines them. 
#Thus, using another solver successively with the same parameters(head1 and head2) will result in the formation of a never ending circular linked list, as the one of the nodes will just end up pointing to itself (try it yourself)
#Thus, this circular linked list will cause an error when you try to print it with the linkedlistnodeprinter function, as the function will never reach a None to stop executing

