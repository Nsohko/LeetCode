class Solution:    
    def canPlaceFlowers(self, flowerbed, n):
        # This is the maximum index of the flower bed
        max_index = len(flowerbed) - 1

        # Special Case: flowerbed only has length of 1, and max_index is 0
        if max_index == 0:
            # check if this the only  spot is equal to 0, which would indicate its empty 
            if flowerbed[max_index] == 0:
                # if so, place a plant there (by setting it to 1), and decrement n by 1
                flowerbed[max_index] = 1
                n-=1
            # check if all n plants have been placed by seeing if n <= 0. If so, return True, else return false.
            # Note that in this special case where max_index is 0, the only possible successful case is if flower bed = [0], n <=1 or flowerbed =[1], n<=0
            if n<= 0:
                return True
            else:
                return False

        # this is the start of the normal algorithm. first check if index 0 is available. index 0 is only dependent on index 1
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            # if it is available, place a plant at index 0 and decrement n by 1
            flowerbed[0] = 1
            n -= 1
            
        # now iterate from index 1 all the way to max_index - 1. Index 0 has been handled above and indec max_index will be handled later        
        for i in range(1, max_index):
            # for each spot, check if its available through 3 requirements. 1. its value is 0, 2. the value of its left neighbour is 0. 3. the value of its right neighbour is 0
            if flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                # if successful, place a plant amd decremnt n
                flowerbed[i] = 1
                n-=1
               
            else:
                continue

        # handle the last index. Similar to how i handled 0 above, for this i only need to check if it is empty and its left index is empty too
        if flowerbed[max_index] == 0 and flowerbed[max_index - 1] == 0:
            flowerbed[max_index] = 1
            n-= 1
            
        # if n <=0, it means I was able to place all n plants. Thus I can return True. Else, i should return False
        if n <= 0:
            return True
            
        else:
            return False

    def canPlaceFlowers2(self, flowerbed, n):
        # Basically the excat same algorithm as above, just with one tweak
        max_index = len(flowerbed) - 1

        if max_index == 0:
            if flowerbed[max_index] == 0:
                flowerbed[max_index] = 1
                n-=1
            if n<= 0:
                return True
            else:
                return False

        
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            flowerbed[0] = 1
            n -= 1

        # uses a while loop from i = 1 to i = max_index -1
        i = 1
        while i < max_index:
            
            # if flowerbed[i] == 1, I know I can ignore the next spot, so i can increment i by 2, and continue the loop
            if flowerbed[i] == 1:
                i += 2
                continue

            # if flowerbed[i] == 0 and flowerbed[i-1] and flowerbed[i+1]==0, I know Ive found a success
            elif flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                flowerbed[i] = 1
                n-=1

            #if i is not incremented by 2 as per above, we can just increment it by 1 as per usual
            i += 1

        
        if flowerbed[max_index] == 0 and flowerbed[max_index - 1] == 0:
            flowerbed[max_index] = 1
            n-= 1
            
       
        if n <= 0:
            return True
            
        else:
            return False

    def canPlaceFlowers3(self, flowerbed, n):
        # same approach as the first soilution, just coded more neatly

        if n == 0:
            return True
        
        max_index = len(flowerbed) - 1

        for i in range(0, len(flowerbed)):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i+1] == 0):
                flowerbed[i] = 1
                n -= 1

                if n== 0:
                    return True
        return False

        

solution = Solution()
flowerbed = [1,0,0,0,]
n = 2

print(solution.canPlaceFlowers2(flowerbed, n))
                

