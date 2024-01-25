class Solution:
    def checkPossibility(self, nums):
        
        # a flag used to check when we have come across a decreasing order. if it is true, that means it is our first time, so we set it to false and move on. if it is false, it means it is our second time, so we can return false
        is_nondecreasing = True

        # iterate from index 1 to the end of the array
        for i in range(1, len(nums)):

            # if current value is less than previous value, it means we have come across a non decreasing array
            if nums[i] < nums[i-1]:

                # if the non-decreasing flag is true, this is our first time, so we can process
                if is_nondecreasing:

                    #set flag to false
                    is_nondecreasing = False

                    # case 1: this is the better case. if the prev_prev_valuue is less than current_value, we can update prev_value to equal cur_val to maintain the non-decreasing order. This is also possible if current index is 1, since in that case there is no prev_prev_value
                    if i==1 or nums[i-2] <= nums [i]:
                        nums[i-1] = nums[i]
                        continue

                    # Case 2: prev_prev value > cur_value. In this case we need to increase cur_value. The minimum value I need to increase cur_val to is prev_val 
                    else:
                        nums[i] = nums[i-1]
                        continue

                else: # if the non-decreasing flag was fasle, it means we have already come across a decreasing sequnce before. Thus, since this our second time, we can immediately return false
                    return False

        # if we loop through the whole list, without coming across more than 1 decreaing sequence, I can return True
        return True

        
        


solution = Solution()

nums = [4,2,1]
#nums = [5,7,1,7]

#print(solution.checkPossibility(nums))
