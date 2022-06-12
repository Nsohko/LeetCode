#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode 
{
	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };
 


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
if (numsSize == 0)
    {
        return NULL;
    }
    
    struct TreeNode *center_node = malloc(1 * sizeof(struct TreeNode));

	int midindex = (numsSize - 1) / 2;
	center_node -> val = nums[midindex];

	center_node -> right = sortedArrayToBST(nums + midindex + 1, numsSize - midindex - 1);
	center_node -> left = sortedArrayToBST(nums, midindex);

	return center_node;
}

// start is the starting index of the list to be considered while end is the ending index of the list to be considerex
// to consider full list, start should be 0 and end should be lenght of array - 1
struct TreeNode* sortedArrayToBST2(int* nums, int start, int end){
if (start > end)
    {
        return NULL;
    }
    
    struct TreeNode *center_node = malloc(1 * sizeof(struct TreeNode));

	int midindex = (end) / 2;
	center_node -> val = nums[midindex];

	center_node -> right = sortedArrayToBST2(nums, midindex + 1, end);
	center_node -> left = sortedArrayToBST2(nums, start, midindex - 1);

	return center_node;
}

int main(void)
{
    return 0;
}
