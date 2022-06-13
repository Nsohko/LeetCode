def rotate1(nums, k):
    leng = len(nums)
    
    nums_copy = [0] * leng
    
    for i in range(leng):
      new_index = (i + k) % leng
      nums_copy[new_index] = nums[i]
    
    # since the want us to modify nume instead of returning new array
    # note we cant do nums = nums_copy since such a reassignemnt iperator would not change nums in global wcope
    for i in range(leng):
      nums[i] = nums_copy[i]
      
def rotate2(nums, k):
  # reverses a subsection of an array in place
  def numsreverse(nums, start, end):
    while start < end:
        temp = nums[start]
        nums[start] = nums[end]
        nums[end] = temp
        
        start += 1
        end -= 1
        
  k = k % len(nums)
  
  numsreverse(nums, 0, k - 1)
  numsreverse(nums, k, len(nums) - 1)
  
def rotate3(nums, k):
  
  
  # number of swaps made. at amx we will only ever need to swap len(nums) times (1 for each num)
  ct = 0
  
  # the original index that we are swapping and its value. this is also equal to the index of the start of our cycle originally! so ill assign start and original to 0
  start = original = 0
  original_val = nums[original]
  
  while True:
    # the new index after rotation
    new = (original + k) % len(nums)
    
    temp = nums[new]
    nums[new] = original_val
    
    # increment ct by 1 since a swap was made
    ct += 1
    
    # check that all swaps have been made
    if ct == len(nums):
      # if so break and exit
      break
      
    # else check that the cycle has not looped on itself
    elif new == start:
      # this indicates a loop has formed
      # to break the loop and continue swapping the rest of the elemnts, ill just create a new loop that is offset by 1. i can guarantee that doing so will result in an index that is not in the previous cycle, since if it was, that means the cycle iterated theough each elemnt and then its next elemnt so every elemnt wpuld be swapped already and ct woukd exceed len(nums) - 1 and the loop wpulf break before this point
      
      # set new start and original of new loop
      start = original = start + 1
      original_val = nums[original]
      continue
    else:
      # if it hasnt looped yet, i can just update and continue
      original = new
      original_val = temp
      continue
      
nums = [1,2,3]

rotate3(nums, 1)
print(nums)
      

 
