# Definition for a binary tree node.
class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

def sortedArrayToBST(nums):
    if len(nums) == 0:
      return None
      
    midindex = len(nums) // 2
    
    center_node = TreeNode(nums[midindex])
    
    center_node.right = sortedArrayToBST(nums[midindex + 1: ])
    center_node.left = sortedArrayToBST(nums[0: midindex])
    
    return center_nod
    
# in python, list indexing is slow, so here is a more optimised method
def sortedArrayToBST(nums, left = 0, right = None):
    if right == None:
      # initial case, as right should initially be len(nums) - 1, but i cant pht that as a default argument
      right = len(nums) - 1
      
    if left > right:
      return None
      
    midindex = (left + right) // 2
    
    center_node = TreeNode(nums[midindex])
    
    center_node.right = sortedArrayToBST(nums, midindex + 1, right)
    center_node.left = sortedArrayToBST(nums[0: midindex], left, midindex - 1)
    
    return center_node
    
    
