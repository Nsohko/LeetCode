#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize){
	for(int i = 0; i < numsSize; i ++)
    {
        // see python soln 2 for epxlanation
        int num = abs(nums[i]);
        int index = num - 1;
        nums[index] = -abs(nums[index]);
    }
    
    // getting size of result array
    int returnSize = 0;
    for (int c = 0; c < numsSize; c++)
    {
        if (nums[c] > 0)
        {
            (returnSize)++;
        }
    }
    
    // question says this will be freed by caller
    int *result = calloc(returnSize, sizeof(int));
	
	for(int i = 0, result_index = 0; i < numsSize; i ++)
    {
        if(nums[i] > 0)
        {
            // the shift of +1 is due to 0 indexing of arrays. so 0 infex in nums correposnds to 1 not 0
            result[result_index] = i + 1;
            result_index ++;
        }
    }
    return result;

}
int main() {
    int nums[] = {4,3,2,7,8,2,3,1};
    
    
    int *result = findDisappearedNumbers(nums,8);
    
    for(int i = 0; result[i] != 0; i ++)
    {
        printf("%d\n", result[i]);
    }
    
    free(result);
    
    return 0;
}
