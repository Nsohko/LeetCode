# Definition for a binary tree node.
 class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right
         
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        # this is my output node
        output = TreeNode()

        # Base Case 1: root1 is None. This means we've reached the end of root1
        if root1 == None:
            # Thus, the rest of the tree from here, would just be root2. Thus, I set output = root2 and return it
            output = root2
            return output
        
        # Base Case 2: root2 is None. This means we've reached the end of root2
        elif root2 == None:
            # Thus, the rest of the tree is just root1. So I assign output = root1 and return it
            output = root1
            return output
        
        else:
            # otherwise, if both root1 and root2 are not none, the value of the current Node is root1.val + root2.val
            output.val = root1.val + root2.val

            # recurisvely form the left and right sides of output
            output.left = self.mergeTrees(root1.left, root2.left)
            output.right = self.mergeTrees(root1.right, root2.right)
        
        return output
