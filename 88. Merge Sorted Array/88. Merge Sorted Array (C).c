#include <stdio.h>

// this problem is a bit hard to explain, so I think it's best to look at the leetcode question 
void MergeArray(int nums1[], int m, int nums2[], int n)
{
    // this algorithm is using the traditional merging algorithm used in mergesort, except that it fills in the array in reverse order, ie largest to smallest
    // the question specifies the nums1 has "slack space" at the end to store the extra numbers from num2. Thus, this algorithm simply seeks to store the final merged sorted array in nums1
    // we will fill out nums1 from the back of the slack space
    // basically we iterate from the back of the value of nums1 and nums2 each time adding the larger one to end of num1's slack space 

    // index1 corresponds to the last value initially in nums1, after which the slack space starts
    int index1 = m - 1;

    // index 2 corresponds to last value in nums2
    int index2 = n - 1;
    
    // curindex is the index in nums1, where we are placing the obtained value after comparing index1 in nums1 and index2 at nums2. We starts at the end of the slack space, which has an index of m + n - 1 and slowly work backwards
    int curindex = m + n - 1;
    
    // these two conditions check that we have not reached the end of either nums1 or nums2 as we seek to take their values
    while (index1 >= 0 && index2 >= 0)
    { 
        
    	int val1 = nums1[index1];
    	int val2 = nums2[index2];

        // if val1 >= val2, we must put val1 at curindex of nums1, which will start putting it into the slack space. Note since we are building the list backwards, we place the larger value first
        if (val1 >= val2)
        {
            nums1[curindex] = val1;
            
            // since we placed val1 from nums1, our index in nums1 can move by one place behind as we start comparing the previous value in nums1. We are moving backwards through nums1 from largest to smallest
            index1--;
        }
        // same thing as above, except if val2 > val1, we must put val2 at curindex of nums1 instead.
        else if (val2 > val1)
        {
            nums1[curindex] = val2;
            
            // since we placed val2 from nums2, our index in nums2 must move back by one place, as we have to compare the previous value of nums2. We are moving backwards through nums2
            index2--;
        }

        // After placing the larger value at curindex on nums1, the next largest value will be placed in the previous spot of nums1, since we are building it backwards. Thus, curindex must be deceremnted
        curindex--;
    }
    // after this, there are 2 cases:
    // case 1: we reached the end of nums1 in our search for val1, but there are still smaller values in nums2 since index2 >= 0, we have not reached end of nums2
    // thus, we have to continue iterating though nums2, and putting its values into the correct index in nums1 to form the output list
    // we do this by continuing to work backwards
    while (index2 >= 0)
    {
        nums1[curindex] = nums2[index2];
        index2--;
        curindex--;
    }
    // case 2: we reach the end of nums2 (so index2<0), but there are still smaller values in nums1 that we have not checked yet as index1>= 0
    // since in this algorithm we built our output list directly into nums1, these remaining values of nums1 would already be stored in nums1, in their correct index (since nums1 was initially ordered already). Thus, no action is needed
    
}

int main() {
   // m is the number of significant values stored in nums1, excluding slack space 
   int m = 4;
   // n is the number of significant values tired in nums2
   int n = 3;
   // note that nums1 is initiated with a length of m + n despite only storing m values in its first m indices. This is to give it sufficient space ("slack space") to hold the entire resultant array after nums1 and nums2 are merged, which will have a total length of m + n
   int nums1[4 + 3] = {1,2,5, 8};
   int nums2[3]= {3, 4, 7};
   
   // rmbr, this function just modified nums1 array directly. It does not have a return value
   MergeArray(nums1, m, nums2, n);
   
   for (int i = 0; i < m + n; i++)
   {
       printf("%d\n", nums1[i]);
   }
    
   return 0;
}
