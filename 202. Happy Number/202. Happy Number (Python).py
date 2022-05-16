# my first solution that make use of recursion
# note that I give a default value to seenvals as none, rather than an empty set. Instead, I initialise it as an empty set within the function 
# this is because of the interesting way python handles default mutable arguments. The default argument mutable object is created in the def statement, and successive calls to the function using the default argument, will repeatedly call that same default argument object
# for eg, consider the function 
# def test(testlist = []): 
#     testlist.append(5)
#     return testlist       
# (calling the function once) test() -> returns testlist = [5]
# (calling the function a second time) test() -> returns testlist = [5,5]
# (calling the function third time) test() -> returns testlist = [5,5,5]
# thus, as seen, the default mutable argument used in every function call is the exact same list, and it will be modified for all instances of the function. This is because the default parameter called always has the same addresses (due to pythons handling of mutable objects), causing the same list object to be called every time
# since lists, sets, etc are mutable, every time they are modified, there address remains the same, unlike for non mutable data, eg strings, integers, etc, which will create a new address to store the modified data. This, since a function in python will always retrieve its default parameter from a specific address that is initial used during function definition, for mutable arguments, as the functions are called, the specific mutable object at that exact address is directly modified, which will affect future calls of the function with the default argument
# to avoid such issues, it is better to initialise mutable arguments inside the list
def isHappy1(num, seenvals = None):
    # seen seenvals is initial used as None in the original function call, using the default value. By checking that seenval == None, I know that I am on the original function call, so I can initialise seenvals to an empty set. This, seen sls is no longer equals to None, so as the function is called recursively again, this if statement won't execute, so seenvals will not be re initialised, allowing seenvals to accurate keep track of seenvals as it passed through the recursive function 
    # writing this way also ensures that seenvals is unit lauded as an empty set every time the parent function is called in main caller, before it enters recursion. By ensuring that it is always empty, it will not affect future parent calls of this parent function in the main caller, avoiding the issue of mutable default arguments that would arise if I set seenvals to an empty set as its default value. Note: parent call of a recursive function/ parent function in the context of a recursive function refers to the original call of the function in the main caller, before it entered recursion 
    if seenvals == None:
      # seenvals is a set that keeps track of all the values of sum that we have seen so far. If we get a value of sun that is in the set, it means we have entered a cycle, which means the number cannot be happy
      # we use a set as it is constant time to check whether a particular value is in a set in python, since it acts as a hash table 
      seenvals = set()
    # sum is the sum of the squares of the individual digits of the number
    sum = 0
    # my algorithm is able to split the number into its digits by finding the remainder when it is divided by 10, then after that dividing the number by 10, and finding the floor. By looping this process, we can obtain each individual digit in the number
    # if num == 0, it means we have successfully exhausted every digit in the original number
    # thus, this while loop serves to loop through to obtain each individual digit in the original number, before squaring them and adding them together as the sun variable
    while num > 0:
      # this obtains the current digit in the ones place
      curdigit = num % 10
      # this adds the square of that digit to sun
      sum += (curdigit)**2
      # this finds the floor of division of num by 10. It essentially throws away the digit in the ones place(which we don't need anymore since we considered it already) and shifts all the other digits to the right
      # for eg, the number in the tens place moves to the ones place and so on
      # this allows the loop to work by constantly shifting the digits in num to the right, one step at a time, and acting on the ones digit, until all digits are exhausted, and the num == 0
      num = num // 10
    # if the value of sum at this point is in seenvals already, it means we have entered a loop already, and sum never reached 1, thus, num was not a happy number 
    # note the use of the 'in' operator is a constant time process in this case since seenvals is a set that acts as a hash table
    if sum in seenvals:
      return False
    # on the other hand, if sum == 1, it means num was indeed a happy number, based on the definition of happy number
    elif sum == 1:
      return True
    # else, we must continue recursively doing this process until we get a value of sum that is either in seenvals (if nums is not happy) or a value of sum that equals 1 (if nums is happy)
    else:
      seenvals.add(sum)
      return isHappy1(sum, seenvals)
      
# this is an alternative iterative solution
def isHappy2(num):
  # initliase seenvals as an empty set. seenvals serves the same purpose as in the above solution
  seenvals = set()
  # this loop keeps checking whether num is in seenvals or not. Note that later, num will be updated to equal the value of sum. If the value of num is in seenvals, that means that we have entered a loop, without ever reaching 1. Thus, the original number was not happy
  while num not in seenvals:
    # adds the current value of num to the seenvals set
    seenvals.add(num)
    # this uses the exact same method as above to find the sun of the squares of each digit 
    sum = 0
    while num > 0:
      sum += (num % 10) ** 2
      num = num // 10
    # checks whether sum is 1, if so, the original number must have been happy
    if sum == 1:
      return True
    # else, updates num to equal sun and continues through the loop, now testing the value of sum. This loop will keep going until we get a value of sum that is either in seenvals (if nums is not happy) or a value of sum that equals 1 (if nums is happy)
    else:
      num = sum
      continue
  else:
     return False

# just a helper function to calculate the sum of the square of the digits in a number
def squaresum(num):
  sum = 0
  while num > 0:
    curdigit = num % 10
    sum += curdigit**2
    num = num // 10
  return sum
    
# this uses Floyd's cycle detection algorithm, the same that is used in my C solution for this same problem. For the explanation, please see the C solution
def isHappy3(num):
  slow = fast = num
  while fast != 1:
    slow = squaresum(slow)
    fast = squaresum(squaresum(fast))
    
    if slow == fast and fast != 1:
      return False
  else:
     return True
     


print(isHappy1(13))
print(isHappy2(19))
print(isHappy(23))
