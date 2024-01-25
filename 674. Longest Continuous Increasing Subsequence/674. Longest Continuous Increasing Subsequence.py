class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:

        # stores the length of the longest increasing subsequence so far
        best_length = 1

        # stores the current length of the current increasing subsequence
        cur_length = 1

        # iterate from 1 to the end of the list
        for i in range(1, len(nums)):

            # if current value > previous value, Ive come across an increasing subsequence
            if nums[i] > nums[i-1]:
                # thus, add 1 to cur_length
                cur_length += 1

                # if current_length exceed best_length, update best_length
                if cur_length > best_length:
                    best_length = cur_length
                    
            # if current_value<= previous value, Ive reached the end of the increasing subsequence, so I shoudl restart current_length at 1
            else:
                cur_length = 1
                
        return best_length
