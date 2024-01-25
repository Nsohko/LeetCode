# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:

        # base case: when i reach the end of a tree, return none
        if root == None:
            return None

        # case 1: if root.val < lower_bound, the new root will be root.right (which has a larger val than root). I can recurisvely call trimBST on it
        elif root.val < low:
            root = self.trimBST(root.right, low,high)
            return root

        # case 2: if root.val > upper_bound, the new root will be root.left (which has a smaller val than root). I can recurisvely call trimBST on it
        elif root.val > high:
            root = self.trimBST(root.left,low,high)
            return root
        
        # case 3: root.val is within the bounds, so it will remain as root. Thus, I can rescurisvely call trimBST to form its right and left     
        else:
            root.left = self.trimBST(root.left, low, high)
            root.right = self.trimBST(root.right, low, high)
            
            return root
