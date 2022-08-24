import collections

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

# a dfs solution
def invertTree(root):
  stack = [root]
  while stack:
    current = stack.pop()
    if current:
        current.left, current.right = current.right, current.left
        stack.append(current.left)
        stack.append(current.right)
  return root
  
  
# a bfs solution
def invertTree(root):
  queue = collections.deque([(root)])
    while queue:
        node = queue.popleft()
        if node:
            node.left, node.right = node.right, node.left
            queue.append(node.left)
            queue.append(node.right)
    return root
