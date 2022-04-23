def isvalidparenthesis(inp):
  complement = {'(' : ')', '[' : ']', '{' : '}'}
  parstack = []
  top = -1 #this is just the current index of the parstack. It starts at -1 and increments by 1 after every item is added. So after the first item, top will be 0 (since index is 0). Thus top = -1 means an empty stack
  Empty = True
  for i in inp:
    if i in ['(', '[', '{']:
      parstack.append(i)
      Empty = False
      top += 1
    elif top > -1 and i == complement[parstack[top]]:  #dDont use 'is', use == to check for equality. The 'is' operator checks for reference equality, ie the two objects must have the same address and literally be the exact same object. The == operator checks for value equality, so the two objects only need the same value
      parstack.pop()
      top -= 1
    else:
      return False
  if top == -1 and not Empty:
    return True
  else:
    return False
    
    
    

# For isvalidparenthesis2, I initialise the stack with a 0 that maps to none. This lets me avoid needing to check if the stack is empty or not in case I get a ')' ']' '}' as my first char, as I simply map 0 to none. Thus, since nothing maps to 0, it will return false if it comes across a closing parenthesis as the first term. This also lets me just check if parstack is [0] at the end to see if its empty instead of using top 
# Also using pop auto returns the last value of the list after removing it. I can exploit that to just call pop and check its value with the complemnt of the next value. If they match, i can continue (since i already popped it). Else i just return False

def isvalidparenthesis2(inp):
  complement = {0 : None, '(' : ')', '[' : ']', '{' : '}'}
  parstack= [0] 
  Empty = True
  for i in inp:
    if i in complement:
      parstack.append(i)
      Empty = False
    elif complement[parstack.pop()] != i:
      return False
  if parstack == [0] and not Empty:
     return True
      


inp='()'
print(isvalidparenthesis(inp))
print(isvalidparenthesis2(inp))

   
   


