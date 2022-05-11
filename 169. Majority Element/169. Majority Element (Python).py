# this is the first solution. It is not as optimal as it requires linear time and linear space (due to the dictionary). However, it is easier to devise
def majorityElement1(nums):
    # initiliases a dictionary called valfreq that stores data in the form of value - frequency pairs, where frequency is the number of times that specific value has appeared in the list so far 
    valfreq={}

    # iterates through the list
    for i in nums:
      # checks whether the current value, i, is already in the dictionary. If i is in the dictionary already, it just increments it's associated frequency by 1. If i is not in the dictionary, it creates a new entry, and sets the frequency to 1
      if i in valfreq:
        valfreq[i] += 1
      else:
        valfreq[i] = 1
      
      # upon updating the dictionary, the algorithm checks whether the frequency of that value exceeds len(nums) / 2, which is the threshold for the value to be considered a majority value
      # if it does exceed, it means i is the majority value, so the function returns i 
      if valfreq[i] > len(nums) / 2:
        return i
        
      # if the function iterates through the whole list, without the frequency of a single list exceeding len(nums) / 2, it means there was no majority value present
      else:
        print("No majority value present")
       
# this is the alternative solution that runs in linear time and constant space (compared to solution 1 which was linear time and linear space)
# this uses the exact same algorithm as the C solution, so check that for more documentation 
# see the C solution for the formal name of this algorithm 
def majorityElement2(nums):
  # This solution first considers a testval, which is initialised to be 0th index value of the list. As we iterate through the list, every time we see the same value, the integer count is incremented by 1. Every time we see another value, count is decremented by 1
  # if count equals 0, testval changes to be the current value that we are on as iterate through the list.
  # if a majority element is present (ie a value that is present in MORE than half the list, the value of testval at the end will always equal the majority value. This is because we can essentially think of different values "balancing out" each other. However, since the majority value is present for more than half the list, even after it gets "balanced out" by the all the other values in the list, som elements with the majority value will be "left over", resulting in testval equaling the majority value (see the C code for the more mathematical proof)
  # in the case that there is no majority value, this algorithm will return an arbitrary value with no significance, thus, it is important for us to check that returned value at the end truly is the majority value, as the initial algorithm cannot identify whether there is a majority element or not, and thus whether or not it's returned value is significant 
  testval = nums[0]
  # initliase count as 0, as we are iterating through the whole list below, including 0 index. Thus, we technically have yet to actually see this value, so that's why count starts at 0. In the C solution we only iterate from 1st index, so the 0th index value, which initially equals testval, is already considered seen, which is why we initiated count as 1 in the C solution
  count = 0
  # iterate through the list
  for i in nums:
    # if count ever equals 0, change the testval to the current value in the iteration loop, i, and reset count to 0, since now only 1 i has been detected 
    if count == 0:
      testval = i
      count = 1
      continue

    # if testval equals i, increment count by 1
    if testval == i:
      count += 1

    # else, decrement count by 1
    else:
      count -= 1
  # at the end of the iteration return the final value of testval, which is the algorithms "guess" of a candidate to be the majors value

  # next, we must verify that the value is indeed majority
  ismajority = False
  majoritycount = 0
  
  # iterate through the list and see how many times the final testval, which is the best candidate to be the majority value, appears in the list
  for i in nums:
    if i == testval:
      majoritycount += 1

  # if the testval appears more than len(nums) / 2 times, it must be the majority value
  if majoritycount > len(nums) / 2:
    return testval
  # else, there was no majority value, and the value returned was arbitrary. We can confidently say there was no majority value, since the algorithm above will always return the majority value if there is one present
  else:
    print("No majority value present")
    
nums= [6,5,5]
print(majorityElement1(nums))
print(majorityElement2(nums))
