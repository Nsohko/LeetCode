def merge(nums1, m, nums2, n):
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # m is length of useful numbers in nums1 (excluding slack space). n is length of useful numbers in nums 2
        
        # finding max index
        index1 = m - 1
        index2 = n - 1
        
        # this is the position i am apeendinng to in list 1
        curindex = m + n -1
        
        while index1 >= 0 and index2 >= 0:
          val1 = nums1[index1]
          val2 = nums2[index2]
          if val1 >= val2:
            nums1[curindex] = val1
            index1 -= 1
          elif val2 > val1:
            nums1[curindex] = val2
            index2 -= 1
          curindex -= 1
        else:
           while index2 >= 0:
             nums1[curindex] = nums2[index2]
             index2 -= 1
             curindex -= 1
             

nums1 = [1,4,5,0,0,0]
nums2=[2,6,8]

merge(nums1, 3, nums2, 3)

print(nums1)
         
