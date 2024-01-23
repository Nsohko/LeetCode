# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    # recursive solution
    def preorder(self, root):
        # Base case. root == None
        if root == None:
            return None
        
        else:
            # create a list with root's val
            output = [root.val]

            # then append the preorder traversal of each child. This is done throgh recursion. Note that when children is None, python is able to ignore the 'for i in None' statemnt without an error
            for child in root.children:
                output += self.preorder(child)
                
            return output

    # iterative solution
    def preorder_iter(self, root):

        # special case if root is None
        if root is None:
            return []

        # uses a stack
        stack = [root]
        # this will be output list
        output = []

        # loop while there are items in the stack yet to be explored
        while stack:

            # get the last node in the stack, which was the most recent to enter
            cur_node = stack.pop()

            # add its value to output
            output.append(cur_node.val)
            
            # iterate through the node's children and add them to the stack fro exploration. Note that we need to add them to the stack in reversed order, since we want to explore left first then right. thus, the rightmost child must be added to the stack first and the leftmost child the ;ast
            for child in reversed(cur_node.children):
                stack.append(child)


        return output
