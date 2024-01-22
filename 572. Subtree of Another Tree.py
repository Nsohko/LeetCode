#Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    # helper function to check if 2 trees are equal
    def isEqualtree(self, root1, root2):
        # Base Case: If either one of the roots is None
        if root1 == None or root2 == None:
            # This should only return true if both roots are None. Otherwise it should be false
            return root1 == root2
        
        # Case 1: Both current values are the same. We can continue recurisvely checking their equality
        if root1.val == root2.val:
            # Check equality on left and right sides
            return self.isEqualtree(root1.left, root2.left) and self.isEqualtree(root1.right, root2.right)
        # Case 2: Current Values are different. Thus, we can immediately return False
        else:
            return False

    # Solution function
    def isSubtree(self, root, subRoot):
        # Base case: if root reaches its end, I can immediately return False. I only need to check root since root is the only one being explored left adn right below. subroot never moves. 
        if root == None :
            return False
        
        # check if subRoot is already equal to the current tree. If so, return true
        if self.isEqualtree(root, subRoot):
            return True
        else:
            # otherwise, let's recurisvely check if the subRoot is in the left or right of root
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
            
#head1 = TreeNode(4, TreeNode(1), TreeNode(2, TreeNode(0)))
#head2 =  TreeNode(4, TreeNode(1), TreeNode(2, TreeNode(0)))

head1 = TreeNode(4, TreeNode(1), TreeNode(2, TreeNode(0)))
head2 = TreeNode(4, TreeNode(1), TreeNode(2))

solution = Solution()
print(solution.isEqualtree(head1,head2))

