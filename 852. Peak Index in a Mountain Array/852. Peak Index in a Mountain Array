class Solution(object):
    def peakIndexInMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # This is a basic binary search algorithm to find the highest value in the array
        midindex = (len(arr)-1) // 2
        
        left_bound = 0
        right_bound = len(arr) - 1
        
        while not (arr[midindex-1] < arr[midindex] and arr[midindex] > arr[midindex+1]):
            if arr[midindex-1] > arr[midindex]:
                left_bound = left_bound
                right_bound = midindex
                
                midindex = (left_bound + right_bound)//2
                
            elif arr[midindex] < arr[midindex + 1]:
                left_bound = midindex
                right_bound = right_bound
                
                midindex = (left_bound + right_bound)//2
            
        return midindex
        
        
        
