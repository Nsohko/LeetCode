#include <stdio.h>
#include <stdbool.h>

// a macro to get the length of an array
#define length(array) sizeof(array)/sizeof(array[0])

// this is a very interesting solution, that uses the Boyer–Moore majority vote algorithm, to find a majority value in linear time and constant space
int majorityElement(int* nums, int numsSize)
{
    // this solution essentially works by having a counter that ticks up everytime the same value as testval is identified, and ticks down when a different value is identified 
    // when count reaches 0, the algorithm will pick the next value to be the testval, repeating the process till the end of the list is reached
    // if a majority value is present, the testval at the end will be equal to the majority val. See math below
    // consider a list with 2n elements. If there is a majority element, it will appear > (2n / 2) times in the list. Thus, it will appear > n times in the list from the definition of a majority value
    // let n + x be the frequency of appearance of the majority value, where x > 0. Thus, as I iterate through the list, I will come across this value n + x times, and I will come across the other elements (2n - (n + x)) = n - x times
    // every time I find the majority value, my count goes up by 1, and every time I see another value, it will go down by 1. Since frequency of majority value is (n + x) while frequency of other values is (n - x), the final value of count will be ((n + x) - (n - x)) = 2x. Since 2x > 0, the final testval will always equal the majority value, if one is present
    // even if at the start, because there are more other values initially, it is possible for count to reach 0, which will cause the testval to change. However, over the entire list, as long as there is a majority val, there will be some majority val "left over" after "balancing" the other values, which will always result in testval equaling majority value, if one is present 
    // however, note that this is entirely based on the premise that there is a majority value in the list, ie a value that appears MORE than n times in a list of length 2n.
    // in the case that no majority element is present, this algorithm will just return an arbitrary value, based on the specific list. However, the algorithm itself cannot identify that there is no majority value, and the arbitrary value returned has no significance 
    // thus, it is important to check that the value returned by the algorithm truly is the majority value, by counting its frequency in the list and checking that it is more than n. This is done below
    
    // testval is initlaised s the first element as the list. However, it will be dynamically updated as we iterate through the list. It can be thought of as a "guess" of the majority value, that the algorithm checks by measuring its count value
    int testval = nums[0];

    // since we start with testval as the first element and we have seen it once in the first position, we initialise count to 1
    int count = 1;

    // we iterate through the list from the first index. Note that we already considered the 0th index above
    for(int i = 1; i < numsSize; i++)
    {
        // in the case where count == 0, the algorithm updates it's "guess" in the form of textval to be the next value in the list, and sets count back to 0.  This way we are essentially trying to "balance out" all the values in the list, and see which value is "left over", as this value would have a count > 0. This is the majority value
        if (count == 0)
        {
            testval = nums[i];
            count = 1;
            continue;
        }
        
        // if the current value equals the testval, count is incremented by 1
        if (nums[i] == testval)
        {
            count++;
        }
        // if the current value does not equal the testval, then count is decreased by 1
        else
        {
            count--;
        }
    }
    
    // this section of the code just serves to check that the final testval returned above truly is a majority value
    // this is because, as noted, in the case of no majority value, the algorithm returns an arbitrary value with no significance. The algorithm itself cannot actually detect whether there is a majority element or not. 
    // while in the case that there IS a majority element, the algorithm will always return the correct value, in the case where there is no majority value, the algorithm cannot detect.
    // thus, we must check that the value truly is a majority value by counting it frequency. In the case that it's frequency is more than the threshold, it is the majority value. If it's frequency is less than the threshold, there is no majority value.
    bool ismajority = false;

    // this is the frequency count of the final testval, that is a candidate to be tge majority value
    int majoritycount = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if (nums[i] == testval)
        {
            majoritycount++;
        }
    }
    
    if (majoritycount > numsSize / 2)
    {
        ismajority = true;
    }
    
    if (ismajority)
    {
        return testval;
    }
    else
    {
        printf("No majority value");
        return 0;
    }
}

int main() 
{
    int nums[] = {2,2,1,1,1,2,2};
    int majority = majorityElement(nums, length(nums));
    printf("Majority is %d", majority);
    return 0;
}
