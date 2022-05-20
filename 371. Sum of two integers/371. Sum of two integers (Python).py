# this uses largely the same method as the second solution in the C solution
# in python, I can skip the casting issues that arose when this exact algorithm was implemented in C
# however, some different python specific 
# python stores integers in a very unique way. It does not assign 32 bits to an integer, instead it effectively assigns infinite, as it scales based on the integer size 
# thus, integers are of varied sizes in python. Python stores negative values using two's complement representation
# we can also think of an infinite number of leading 0s for positive numbers and an infinite number of leading 1s for negative numbers
def BinarySum(a, b):
    # MAX_INT just equals the max value of a 32 bit signed integer. This is because this peer code problem assumes we are using 32 bit integers. This will be used later
    MAX_INT = 0x7fffffff
    
    # mask is just an unsigned integer storing a number with 32 bits all set to 1. It can be abstracted that there are a infinite number of leading 0s to the left of the leading 1, since this is a positive number
    mask = 0xffffffff

    # one key consequence of the fact that python stores integers with variable sizes is that the integers in a and b may not have the same number of bits!
    # for the purposes below also rmbr that a and b are just names of integers not the integers themselves. Thus, although a could be initially pointing to an integer with 3 bits(for eg), once I reassign a using the = operator, it will point to a completely new int that need not be the same size


    # the looping condition is the same as C. b will be the name of the integer that we are "carrying". Once b == 0, out carry value is 0, so we can stop
    # a will be the name of the sun of the two integers without the carry. Once the carry value == 0 (ie b == 0) the value of the sun without the carry value (a) will equal the value of the actual sun since the carry value is 0. Thus once b == 0, we can return a
    while b!= 0:
  
      # first we use the XOR (^) operator. Same as C this will give 1 where either a is 1 or b is 1 but not both and will give 0 where both a and b are 0 or both are 1. This perfectly simulates the behaviour of addition while ignoring the carry value
      # to get over the problem that a and b could be of different sizes, Python will essentially pad the shorter numbers (in binary) out till they are of the same length. If the shorter number is positive, Python will pad out with leading 0s. 
      # due to the issue 
      sum = (a ^ b) & mask

      # the use of the first & and << operant here is the same as in C, however, you will also notice the & mask at the end of this line
      # since python can effectively store infinite integers, as it is mathematically assigns infinite bits to an integer, every time the << is carried out, the 1s in b will shift to the left by one spot. However, the thing is, any 1s that exceed the 32 bit from the right won't be thrown away like in C, instead, they will just move onto the 33 bit from the right
      # this is incorrect as this method requires the "excess" bits to be thrown away
      # in certain cases (eg if a < 0 and b > 0), bits will just keep getting pushed to the left without ever getting thrown away. This will result in an infinite loop as the carry value and b will never reach 0
      # thus I must do the & operant with mask. Mad is value where the first 32 bits from the right are 1, while anything beyond that is 0. Doing & mask will this set all bits beyond the first 32 in (a & b) << 1 to 0, ensuring the algorithm works and excess bits are thrown away
      b = ((a & b) << 1) & mask

      a = sum

   
    if a > MAX_INT:
      return ~(a ^ mask)
    else:
      return a

# note overall I think the best algorithm is the one used in first C solution
# although it is longer, it is more universal, and does not take any risky language specific moves
# it can easily be directly implemented in python 
